'''
안녕하세요, 매일프로그래밍 이번주 문제입니다.
Hi, today's 매일프로그래밍 problem.

정렬된 정수 배열이 주어졌을 때, 주어진 수가 존재하는 배열의 첫 번째 위치와 마지막 위치를 찾으시오.
When there is given sorted integer array, find the first and last index of given number in this array.
 

배열에 찾는 수가 없다면 없다고 출력하세요.
If it doesn't exsit, print "None".


Input:

A = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9]

target = 5

Output:

첫 번째 위치는 인덱스 1
first index is 1

마지막 위치는 인덱스 3
last index is 3


Input:

A = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9]

target = 4

Output:

찾는 값 없음
None
'''

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
