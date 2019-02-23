## Merge String Alternatively

def mergedString(a, b):
    a_len = len(a)
    b_len = len(b)
    if a_len == 0 and b_len == 0:
        return ""
    if a_len == 0:
        return b
    if b_len == 0:
        return a

    result = []
    min_val = min(a_len, b_len)
    index = 0
    a_str = True
    while index < min_val:
        if a_str:
            result.append(a[index])
            a_str = False
        else:
            result.append(b[index])
            a_str = True
            index += 1

    if index < a_len:
        result.append(a[index:])
    else:
        result.append(b[index:])

    return "".join(result)


if __name__ == '__main__':
    a = "abcasds"
    b = "def"
    print(mergedString(a, b))
