stores = [1, 5, 20, 11, 16]
houses = [5, 10, 17]


# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solutionA(stores, houses):
    # write your code in Python 3.6
    result = []
    for i in range(0, len(houses)):
        minDiff = 1000001
        closestStoreIndex = -1
        for j in stores:
            currentDiffer = houses[i] - j
            if abs(currentDiffer) == abs(minDiff):
                if currentDiffer < minDiff:
                    minDiff = currentDiffer
                    closestStoreIndex = j
            elif abs(currentDiffer) < abs(minDiff):
                minDiff = currentDiffer
                closestStoreIndex = j
        result.append(closestStoreIndex)
    return result

def solution(stores, houses):
    # write your code in Python 3.6
    maxStore = max(stores)
    maxHouses = max(houses)
    currentStore = min(stores)

    hashStores = [0] * max(maxHouses, m
    for i in stores:
        hashStores[i] = i

    for i in xrange(0, maxHouses):
        if hashStores[i] > currentStore:
            currentStore = hashStores[i]
        hashStores[i] = currentStore
    result = []

    for j in houses:
        result.append(hashStores[j])

    return result


print (solution(stores, houses))


