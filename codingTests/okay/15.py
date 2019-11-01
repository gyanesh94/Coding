def getSubsequence(inputList):
    if len(inputList) == 0:
        return []

    index_map = {}
    for i in range(len(inputList)):
        value = inputList[i]
        # Need to know the last index of the current value
        index_map[value] = i

    result = []
    start = 0
    while start < len(inputList):
        last = index_map[inputList[start]]
        current_index = start
        while current_index < last:
            current_index += 1
            last = max(last, index_map[inputList[current_index]])
        result.append(last - start + 1)
        start = current_index + 1

    return result


if __name__ == "__main__":
    data = ['a', 'b', 'a', 'b', 'c', 'b', 'a', 'c', 'a', 'd', 'e', 'f', 'e', 'g', 'd', 'e', 'h', 'i', 'j', 'h', 'k', 'l', 'i', 'j']
    print(getSubsequence(data))
