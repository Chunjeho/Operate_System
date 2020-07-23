def FindMin(_string, _minimum):
    for str in _string:
        if(len(str) <= len(_minimum)):
            _minimum = str
        else:
            continue
    return _minimum

str1 = ['CATGC', 'CTAAGT', 'GCTA', 'TTCA', 'ATGCATC']

commonChar = []
indexStr1 = {} #str1 순방향 검사 
indexStr2 = {} #str2 역방향 검사

min = min(str1, key=len)
minLen = len(min)
checkArr = {}

for i in range(minLen):
    if(i>0):
        checkArr[min[:i]] = 0
        checkArr[min[i:minLen]] = 0

str1.remove(min)

for str in str1:
    for i in range(minLen):
        if(str[len(str)-i:len(str)] == min[:i] and i > 0):
            checkArr[min[:i]] = 1
            commonChar.insert(0, min[:i])
            indexStr1[min[:i]] = str

        if(str[:i] == min[i:minLen] and i > 0):
            checkArr[min[i:minLen]] = 1
            commonChar.insert(0, min[i:minLen])
            indexStr2[min[i:minLen]] = str

print(max(commonChar, key=len))
print(indexStr1, indexStr2, min)

