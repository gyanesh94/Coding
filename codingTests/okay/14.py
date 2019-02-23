def createDivisors(n, threshold):
    divisors = dict()
    for number in range(1, n + 1):
        temp = set()
        for div in range(number, threshold, -1):
            if number % div != 0:
                continue
            if divisors.get(div, None) is None:
                temp.add(div)
            else:
                temp = temp.union(divisors[div])
                break

        divisors[number] = temp

    return divisors


def connected(cities, o, d, already_visited):
    neighbors = cities[o]
    if d in neighbors:
        return True

    result = False
    for neighbor in neighbors:
        if neighbor in already_visited:
            continue
        already_visited.append(o)
        result = connected(cities, neighbor, d, already_visited)
        if result:
            cities[o].add(d)
            cities[d].add(o)
            return result
        already_visited.pop(-1)
    return result


def connectedCities(n, g, originCities, destinationCities):
    divisors = createDivisors(n + 1, g)
    cities = dict()
    for o in originCities:
        cities[o] = set()
    for d in destinationCities:
        cities[d] = set()

    for o in originCities:
        for d in destinationCities:
            for o_s in divisors[o]:
                if o_s in divisors[d]:
                    cities[o].add(d)
                    cities[d].add(o)
                    break

    result = []
    for i in range(len(originCities)):
        if connected(cities, originCities[i], destinationCities[i], []):
            result.append(1)
        else:
            result.append(0)
    return result


if __name__ == '__main__':
    n = 20
    g = 2
    originCities = [1, 2, 3, 4, 5, 11]
    destinationCities = [6, 7, 12, 9, 10, 6]
    result = connectedCities(n, g, originCities, destinationCities)
    print(result)
