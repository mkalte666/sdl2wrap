import clang.cindex
import sys, os
import re
from pathlib import Path
from strops import *

def operatorLine(retType, op, atype, btype):
    result = """\
inline %(retType)s operator%(op)s (%(atype)s a, %(btype)s b) noexcept 
{ 
    return a %(op)s static_cast<%(atype)s>(b); 
}\n""" % {"retType":retType, "op":op, "atype":atype, "btype":btype}

    return result

def makeEnumOperators(origType, newType):
    result = operatorLine("bool", "==", origType, newType)
    result += operatorLine("bool", "==", newType, origType)
    # perhaps we want these one day?
    # result += operatorLine(origType, "|", origType, newType)
    # result += operatorLine(newType, "|", newType, origType)
    # result += operatorLine(origType, "&", origType, newType)
    # result += operatorLine(newType, "&", newType, origType)
    return result

class EnumConstDecl:
    def __init__(self):
        self.name = ""

    def rewrite(self, parentName):
        niceName = stripPrefixCount(self.name, 2)
        # fixme: this works but whyyyy
        # working around the EventType/SDLK enum here, that just prefixes with SDL_
        if parentName == "EventType" or parentName == "KeyCode":
            niceName = stripPrefixCount(self.name, 1)
        niceName = niceName.lower()
        niceName = niceName.capitalize()
        niceName = re.sub(r"_([a-z0-9A-Z]{1})", lambda pat: pat.group(1).upper(), niceName)
        return niceName + " = " + self.name + ", " \
               + makeImplComment(self.name, parentName + "::" + niceName.strip())

class Enum:
    def __init__(self):
        self.sourceFile = ""
        self.sourceLine = 0
        self.name = ""
        self.constantDecls = []

    def makeScoped(self):
        txt = """
/**
 * \\brief Scoped version of %(origName)s
 * 
 * Generated From %(filename)s:%(line)d
 * \\sa %(origName)s
 */
""" % {"origName": self.name, "filename": os.path.basename(self.sourceFile), "line": self.sourceLine}
        txt += "enum class " + stripPrefix(self.name, "SDL_") + " : Uint32 {\n"
        for decl in self.constantDecls:
            txt += "    " + decl.rewrite(stripPrefix(self.name, "SDL_")) + "\n"
        txt += "};\n"
        txt += makeEnumOperators(self.name, stripPrefix(self.name, "SDL_"))
        return txt


def findRecursion(enumList, file, node):
    try:
        if node.location.file is not None and os.path.basename(node.location.file.name) == os.path.basename(file):
            if node.kind == clang.cindex.CursorKind.TYPEDEF_DECL:
                enum = Enum()
                enum.name = node.spelling
                enum.sourceFile = node.location.file.name
                enum.sourceLine = node.location.line
                for enumDecl in node.get_children():
                    if enumDecl.kind != clang.cindex.CursorKind.ENUM_DECL:
                        return
                    for c in enumDecl.get_children():
                        decl = EnumConstDecl()
                        decl.name = c.spelling
                        enum.constantDecls.append(decl)
                    enumList.append(enum)
                    return
    except ValueError:
        pass
        #print("Warning: got a value error, probs in node.kind. This is meh, but recoverable")
        #print("Position was " + str(node.location))
        #print(sys.exc_info()[0])
    for c in node.get_children():
        findRecursion(enumList, file, c)

def findEnums(file):
    enums = []
    index = clang.cindex.Index.create()
    tu = index.parse(file)
    findRecursion(enums,file, tu.cursor)
    return enums
