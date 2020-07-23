def Permutation(_array, _length):
    _permu1 = [['1']]
    _permu2 = []

    for i in range(2, _length+1):
        for j in range(0, i):
            for k in range(0, len(_permu1)):
                _permu1[k].insert(j, str(i))
                _permu2.append(_permu1[k].copy())
                _permu1[k].remove(str(i))

        _permu1.clear()
        _permu1 = _permu2.copy()
        _permu2.clear()

    return _permu1.copy()

array = ['1','2','3','4']
PerArr = []
PerArr = Permutation(array, len(array))
print(PerArr)