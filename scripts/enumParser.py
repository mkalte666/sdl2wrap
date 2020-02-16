import clang.cindex
import sys, os
import re
from pathlib import Path
from strops import *


class EnumConstDecl:
    def __init__(self):
        self.name = ""

    def rewrite(self):
        niceName = stripPrefixCount(self.name, 2)
        niceName = niceName.lower()
        niceName = niceName.capitalize()
        niceName = re.sub(r"_([a-z0-9A-Z]{1})", lambda pat: pat.group(1).upper(), niceName)
        return niceName + " = " + self.name + ","

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
 */
""" % {"origName": self.name, "filename": os.path.basename(self.sourceFile.name), "line": self.sourceLine}
        txt += "enum class " + stripPrefix(self.name, "SDL_") + " : Uint32 {\n"
        for decl in self.constantDecls:
            txt += "    " + decl.rewrite() + "\n"
        txt += "};\n"
        return txt


def findRecursion(enumList, file, node):
    if node.kind == clang.cindex.CursorKind.TYPEDEF_DECL:
        if node.location.file is not None and Path(node.location.file.name) == Path(file):
            enum = Enum()
            enum.name = node.spelling
            enum.sourceFile = node.location.file
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

    for c in node.get_children():
        findRecursion(enumList, file, c)

def findEnums(file):
    enums = []
    index = clang.cindex.Index.create()
    tu = index.parse(file)
    print("this print prevents a segfault in libclang and i cant even")
    findRecursion(enums,file, tu.cursor)
    return enums
