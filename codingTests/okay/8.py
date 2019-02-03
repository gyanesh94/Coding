votes = ['Alex', 'Michael', 'Harry', 'Dave', 'Michael', 'Victor', 'Harry', 'Alex', 'Mary', 'Mary', 'Mary', 'Victor', 'Victor']

def electionWinner(votes):
    votesList = {}
    maxVotesName = ""
    maxVotes = 0
    for i in votes:
        votesList[i] = votesList.get(i, 0) + 1
        if maxVotes == votesList[i]:
            maxVotesName = max(maxVotesName, i)
        elif maxVotes < votesList[i]:
            maxVotesName = i
            maxVotes = votesList[i]
    return maxVotesName


print electionWinner(votes)