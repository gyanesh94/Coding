givenPattern = ""
output = []

def recurseUniqueCombination(currentPos, hoursPerDay, remainingHours, hoursList):
    global output

    if remainingHours == 0:
        output.append(givenPattern.format(*hoursList))
        return

    hoursListLen = len(hoursList)

    if remainingHours == hoursPerDay * (hoursListLen - currentPos):
        for i in range (currentPos, hoursListLen):
            hoursList[i] = hoursPerDay
        output.append(givenPattern.format(*hoursList))
        for i in range (currentPos, hoursListLen):
            hoursList[i] = 0
        return

    if remainingHours > hoursPerDay * (hoursListLen - currentPos):
        return
    
    if currentPos == hoursListLen:
        return

    for currentHour in range(0, max(hoursPerDay, remainingHours) + 1):
        hoursList[currentPos] = currentHour
        recurseUniqueCombination(currentPos + 1, hoursPerDay, remainingHours - currentHour, hoursList)
        hoursList[currentPos] = 0


def findSchedules(workHours, dayHours, pattern):
    global givenPattern
    global output
    
    hoursList = []
    hoursCompleted = 0

    for i in pattern:
        if i == "?":
            hoursList.append(0)
        else:
            hoursCompleted += int(i)

    givenPattern = pattern.replace("?", "{}")
    recurseUniqueCombination(0, dayHours, workHours - hoursCompleted, hoursList)

    return output

print findSchedules(24, 4, "08??840")