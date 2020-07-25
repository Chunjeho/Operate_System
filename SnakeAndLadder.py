_bowl = [] #kind of buffer memory
_final = [] #storage for some paths or final path(shortest)

_ladder = {1:38, 4:14, 9:31, 21:42, 28:84, 51:67, 72:91, 80:99} # {from:to}
_snake = {17:7, 54:34, 62:19, 64:60, 87:36, 93:73, 95:75, 98:79} # {from:to}
_path = [[1,38],[1,2],[1,2,3],[1,2,3,4,14],[1,2,3,4,5],[1,2,3,4,5,6]]

finish = 0 #Count, if you excess 100 or use for something to count

#make some paths
while(finish < 6):
    for arr in _path.copy():
        for i in range(1, 7):
            _bowl = arr.copy()
            if(_ladder.get(arr[-1])):
                temp = _ladder[arr[-1]]
                _bowl.append(temp)
            elif(_snake.get(arr[-1])):
                temp = _snake[arr[-1]]
                _bowl.append(temp)
            else:
                temp = arr[-1]
            for j in range(i):
                temp += 1
                _bowl.append(temp)
                if(temp >= 100 and temp <= 106):
                    finish += 1
                    _final.append(_bowl.copy())
            _path.append(_bowl.copy())
        _path.remove(arr)
        if(finish == 6):
            break

 #Initiate variables
_final = min(_final, key=len)
_bowl.clear()
_finish = 0

#Count to calculate the shortest path
for k in range(len(_final)-1):
    if(_final[k]+1 != _final[k+1]):
        _bowl.append(_finish)
        _finish = 0

    elif(_final[k]+1 == _final[k+1]):
        _finish += 1
_bowl.append(_finish)

_final.clear()

# Show a dice pips to win this game
for ele in _bowl:
    if(ele == 0): #If you meet ladder in 1 (= dice pip is euqal to 1), in here {1:38} (from 1 to 38)
        _final.append(1)
    else:
        a = int(ele/6) #How many 6 are needed?
        b = ele%6 #pips which are lower than 6
        for l in range(a):
            _final.append(6)
        _final.append(b)

print(_final) #print dice pips
print(len(_final), "times"))


