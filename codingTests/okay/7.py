s = "I am using HackerRank to improve programming"
t = "am HackerRank to improve"


def missingWords(s, t):
    # Write your code here
    s = s.strip().split(" ")
    t = t.strip().split(" ")
    lenS = len(s)
    lenT = len(t)
    j = 0
    i = 0
    result = []
    while j < lenT and i < lenS:
        if s[i] == t[j]:
            j += 1
        else:
            result.append(s[i])
        i += 1

    if i < lenS:
        result = result + s[i:]

    return result


print missingWords(s, t)