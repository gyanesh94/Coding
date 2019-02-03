numbers = [1, 2, 3, 5, 6, 1, 2, 1, 3, 3]


def printNumbers(numbers):
    if len(numbers) <= 1:
        print numbers
    numberCountMap = dict()
    for i in numbers:
        numberCountMap[i] = numberCountMap.get(i, 0) + 1

    frequencyMap = dict()
    for number, frequency in numberCountMap.items():
        if frequencyMap.get(frequency, None) is None:
            frequencyMap[frequency] = frequencyMap.get(frequency, [])
        frequencyMap[frequency].append(number)
    frequencyKeys = frequencyMap.keys()
    frequencyKeys.sort()
    result = []
    for key in frequencyKeys:
        temp = frequencyMap[key]
        temp.sort()
        result.extend(temp)

    return result


def printNumbersShort(numbers):
    """
    return list based on the frequency of the elements in the parameter list
    """
    if len(numbers) <= 1:
        print numbers
    numberCountMap = dict()
    for i in numbers:
        numberCountMap[i] = numberCountMap.get(i, 0) + 1
    return [i[0] for i in sorted(numberCountMap.items(), key=lambda (k, v): (v, k))]


print printNumbersShort(numbers)
