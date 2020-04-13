arr = list(input("Given number list (without comma): "))
target = input("Target number: ")
if target in arr:
    index1 = arr.index(target) #return first index
    print("The first index is "+ str(index1))
    arr.reverse() #last index become first index
    index2 = len(arr) - 1 - arr.index(target) #return last index
    if index1 != index2:
        print("The second index is "+ str(index2))
else:
    print("There is no "+target+" in this list")
