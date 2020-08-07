_alphabet = ["Z","A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y"]
_index = []
_Name = []
_num = int(input("Number: "))

while(1):
    q = int(_num/26)
    r = int(_num%26)
    _index.append(r)
    if(q == 0):
        break
    else:
        _num = q

_index.reverse()

for num in _index:
    _Name.append(_alphabet[num])

print(_Name)
