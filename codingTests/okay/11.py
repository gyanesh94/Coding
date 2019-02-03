a = [6, 1, 3, 46, 1, 3, 9]
k = 47

def solution(a, k):
    hashMap = dict()
    for i in a:
        hashMap[i] = hashMap.get(i, 0) + 1

    result = 0
    print hashMap
    for n in hashMap.keys():
        hashMap[n] -= 1
        
        find = k - n
        # print find
        # print n
        # print hashMap[n]
        if hashMap.get(find, 0) > 0:
            result += 1
            hashMap[find] -= 1

        # hashMap[n] += 1

    return result

print solution(a, k)