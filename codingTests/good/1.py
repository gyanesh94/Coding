testCases = [
    # [['jim likes mary', 'kate likes tom', 'tom does not like jim'], ['jim tom', 'likes']],
    # [['how it was done', 'are you how', 'it goes to', 'goes done are it'], ['done it', 'it']],
    # [['it go will away', 'go do art', 'what to will east'], ['it will', 'go east will', 'will']],
    # [['how it was done done it', 'are you how', 'it goes to', 'goes done are it'], ['done it']],
    # [['how it was done done it', 'are you how', 'it goes to', 'goes done are it'], ['done it it']],
    [['how it was done done it', 'are you how', 'it goes to', 'goes done are it'], ['asds']]
]

"""
Output 1
2 
0 1 

Output 2
0 3
0 2 3

Output 3
0
-1
0 2

Output 4
0 0 3

Output 4
0

"""


def createSentencesDict(sentences):
    allPhrasesDict = {}
    sentenceDict = {}
    i = 0
    for sentence in sentences:
        sentence = sentence.split(" ")
        tempDict = {}
        for word in sentence:
            temp = allPhrasesDict.get(word, [])
            if not temp:
                allPhrasesDict[word] = [i]
            else:
                if i not in temp:
                    allPhrasesDict[word].append(i)
            tempDict[word] = tempDict.get(word, 0) + 1
        sentenceDict[i] = tempDict
        i += 1
    return sentenceDict, allPhrasesDict


def createQueriesDict(sentences):
    sentenceDict = {}
    i = 0
    for sentence in sentences:
        sentence = sentence.split(" ")
        tempDict = {}
        for word in sentence:
            tempDict[word] = tempDict.get(word, 0) + 1
        sentenceDict[i] = tempDict
        i += 1
    return sentenceDict

def textQueries(sentences, queries):
    # Create Sentences Dictionary and Words Dictionary
    # sentencesDict -> (<sentence_number>, (<word>, <count>))
    # allPhrasesDict -> (<word>, [<sentence_no>])
    sentencesDict, allPhrasesDict = createSentencesDict(sentences)
    # Create Sentences Dictionary and Words Dictionary
    # phrasesDict -> (<query_number>, (<word>, <count>))
    phrasesDict = createQueriesDict(queries)

    # For every query
    for phrase in phrasesDict.values():
        result = ""

        # get all the sentences containing first word of the phrase
        # if first word is not present then ther will be no result for the query
        for index in allPhrasesDict.get(phrase.keys()[0], [-1]):
            if index == -1:
                continue

            # Sentence information
            sentenceDict = sentencesDict.get(index)

            # for a word it can't be used more than 10 times
            maxTimes = 11

            # loop in (<word>, <count>) in queries Dictionary
            for word, numberOfTimes in phrase.items():
                maxTimes = min(maxTimes, int(sentenceDict.get(word, 0) / numberOfTimes))
                if maxTimes == 0:
                    break
            if maxTimes != 0:
                while maxTimes > 0:
                    result = result + "{} ".format(index)
                    maxTimes -= 1
        if result == "":
            print -1
        else:
            print result


for i in testCases:
    textQueries(i[0], i[1])
    print
    print