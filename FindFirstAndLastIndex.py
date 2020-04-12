arr = list(input("Given number list (without comma): "))
target = input("Target number: ")
if target in arr:
    index1 = arr.index(target)
    print("The first index is "+ str(index1))
    arr.reverse()
    index2 = len(arr) - 1 - arr.index(target)
    if index1 != index2:
        print("The second index is "+ str(index2))
else:
    print("There is no "+target+" in this list")
