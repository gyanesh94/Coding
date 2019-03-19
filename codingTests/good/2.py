# Word Seek
# Find words in GRID


def read_input():
    result = []
    data = input()
    while data:
        result.append(data)
        try:
            data = input()
        except EOFError:
            data = None
    return result


if __name__ == '__main__':
    grid = read_input()
    words = read_input()
