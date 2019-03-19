def election(votes):
    if votes is None or len(votes) == 0:
        return ""
    vote_result = dict()
    for i in votes:
        vote_result[i] = vote_result.get(i, 0) + 1

    # return sorted(vote_result.items(), key=lambda (k, v): (v, k), reverse=False)[-1][0]

    # python 3 Lambda can't unpack
    return sorted(vote_result.items(), key=lambda kv: (kv[1], kv[0]), reverse=False)[-1][0]


if __name__ == '__main__':
    votes = ["Mary", "Jane", "Jane", "Doe", "Mary"]
    print(election(votes))
