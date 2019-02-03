s = "I am using HackerRank to improve programming"
t = "am HackerRank to improve"


def missingWords(s, t):
    # Write your code here
    string_list = s.strip().split(" ")
    subsequence_list = t.strip().split(" ")
    len_subsequence_list = len(subsequence_list)
    if len_subsequence_list == 0:
        return string_list

    result = []
    j = 0
    for i in range(0, len(string_list)):
        if j == len_subsequence_list:
            result = result + string_list[i:]
            break
        if string_list[i] == (subsequence_list[j]):
            j += 1
        else:
            result.append(string_list[i])

    return result


result = missingWords(s, t)

print "\n".join(result)
