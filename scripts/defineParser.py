import re
import os

class DefineToEnumSettings:
    def __init__(self, prefix, newName, basetype="Uint32", createConverter=False, caseDefault=""):
        self.infile = ""
        self.prefix = prefix
        self.newName = newName
        self.basetype = basetype
        self.createConverter = createConverter
        self.caseDefault = caseDefault

class DefineToEnumResult:
    def __init__(self):
        self.settings = None
        self.enumBody = ""
        self.convertBody = ""

    def makeScoped(self):
        txt = ""
        txt += """
/**
 * \\brief scoped enum for %(prefix)s* defines
 * 
 * Generated from %(filename)s
 * \\sa %(prefix)s*
 */     
""" \
        % {"prefix": self.settings.prefix, "filename": os.path.basename(self.settings.infile)}
        if self.settings.createConverter:
            txt += "enum class " + self.settings.newName + " {\n"
        else:
            txt += "enum class " + self.settings.newName + " : " + self.settings.basetype + " {\n"
        txt += self.enumBody
        txt += "};\n"
        if self.settings.createConverter:
            funcname = self.settings.newName
            funcname = funcname[:1].lower() + funcname[1:]
            funcname += "ToBase"
            funcsig = self.settings.basetype + " " + funcname + "(" + self.settings.newName + " value) noexcept"
            txt += """
/**
 * \\brief convert %(newName)s to its basetype (%(basetype)s)
 */
%(funcsic)s;
#ifdef SDL2WRAP_DEFINITIONS
SDL2WRAP_INLINE %(funcsig2)s {
    switch(value) {
%(convertBody)s
        default: break;
    }
    
    return %(caseDefault)s;
}
#endif // SDL2WRAP_DEFINITIONS
""" \
            % {
                        "funcsic": funcsig,
                        "funcsig2": funcsig,
                        "convertBody": self.convertBody,
                        "caseDefault": self.settings.caseDefault,
                        "basetype": self.settings.basetype,
                        "newName": self.settings.newName
            }
        return txt

def defineToEnum(infile, settings):
    settings.infile = infile
    header = open(settings.infile, "r").read()

    # find hint defines
    allDefines = re.finditer(rf"#define\s+({settings.prefix}([A-Z0-9_]+))\s+(.+)", header)

    result = DefineToEnumResult()
    result.settings = settings
    for i, m in enumerate(allDefines):
        define = m.group(1)
        name = m.group(2)
        hintString = m.group(3)
        # generate a nicer hintName for the c++ enum
        name = name.lower()
        name = name.capitalize()
        name = re.sub(r"_([a-z0-1A-Z]{1})", lambda pat : pat.group(1).upper(), name)
        if settings.createConverter:
            result.enumBody += "    " + name + ", ///< " + define + "\n"
            result.convertBody += "        case "+settings.newName+"::" + name + ": return " + define + ";\n"
        else:
            result.enumBody += "    " + name + " = " + define + ",\n"

    return result
