filename = raw_input()

with open(filename, 'r') as f:
    data = f.readlines()
    data = [i.strip() for i in data]

result = dict()
for log in data:
    domain = log.split(" ")[0]
    result[domain] = result.get(domain, 0) + 1

string = ""
for key, value in result.items():
    string = string + "{} {}\n".format(key, value)

with open("records_" + filename, 'w') as f:
    f.write(string.strip())
