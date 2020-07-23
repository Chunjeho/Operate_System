_str = ['CATGC', 'CTAAGT', 'GCTA', 'TTCA', 'ATGCATC']
_index = ['1','2','3','4','5']

_permu1 = [['1']]
_permu2 = []
_stringArr = []

for i in range(2, len(_index)+1):
    for j in range(0, i):
        for k in range(0, len(_permu1)):
            _permu1[k].insert(j, str(i))
            _permu2.append(_permu1[k].copy())
            _permu1[k].remove(str(i))

    _permu1.clear()
    _permu1 = _permu2.copy()
    _permu2.clear()

for arr1 in _permu1:
    for arr2 in arr1:
        _stringArr.append(list(_str[int(arr2)-1]))
    _permu2.append(_stringArr.copy())
    _stringArr.clear()

for arr3 in _permu2:
    for m in range(len(arr3)-1): #I need to compare arr3[m] with arr3[m+1] => we just need total len(arr3)-1 amount of indexes
        if(len(arr3[m]) >= len(arr3[m+1])):
            for n in range(len(arr3[m+1]), 0, -1):
                if(arr3[m][len(arr3[m])-n:] == arr3[m+1][:n]):
                    #print(arr3[m], arr3[m][len(arr3[m])-n:], arr3[m+1], arr3[m+1][:n])
                    del arr3[m][len(arr3[m])-n:]
                    #print(arr3[m])
                    break

        elif(len(arr3[m]) < len(arr3[m+1])):
            for o in range(len(arr3[m]), 0, -1):
                if(arr3[m][len(arr3[m])-o:] == arr3[m+1][:o]):
                    #print(arr3[m], arr3[m][len(arr3[m])-o:], arr3[m+1], arr3[m+1][:o])
                    del arr3[m][len(arr3[m])-o:]
                    #print(arr3[m])
                    break
        arr3[m] = ''.join(arr3[m])
    arr3[m+1] = ''.join(arr3[m+1]) #In [28], I set a maximum as (arr3's length - 1), so I need to apply arr3[m+1] seperately
    _stringArr.append(''.join(arr3))

#print(_stringArr) #print whole string array

print(min(_stringArr, key=len))

