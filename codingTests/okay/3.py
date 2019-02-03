A = [5, 4, 3, 6, 1]
A = [10, 7, 5, 8, 1, 6, 2, 3, 3, 4, 7]
print (A)


# def findLoc(A, number):
#     l = 0
#     h = len(A)
#     m = int((l + h) / 2)
#     while l < h:
#         if A[m] <= number:
#             l = m + 1
#         else:
#             h = m - 1
#     return h
#
#
# def solution(A):
#     if len(A) == 0:
#         return 0
#     if len(A) == 1:
#         return 1
#     result = []
#     for i in A:
#         index = findLoc(result, i)
#         if index == len(result):
#             result.append(i)
#         else:
#             result[index] = i
#
#     return len(result)

def solution(A):
    if len(A) == 0:
        return 0
    if len(A) == 1:
        return 1
    result = []
    for i in A:
        index = -1
        for j in range(0, len(result)):
            if i < result[j]:
                index = j
                break
        if index == -1:
            result.append(i)
        else:
            result[j] = i
        print (result)
    return len(result)


print(solution(A))