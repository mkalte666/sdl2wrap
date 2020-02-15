import re

def stripPrefixCount(str, count):
    workStr = str
    while count > 0:
        count -= 1
        p = workStr.find("_")
        if p == -1:
            return str
        workStr = workStr[p:]
    return workStr

def stripPrefix(str, name):
    return re.sub(name,"",str)