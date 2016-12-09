import sys

lines = []
for line in sys.stdin: 
    lines.append(line.strip())

count = 0
for line in lines:
    parts = line.split('-')
    join = ''.join(parts[:-1])
    id, given = parts[-1][:-1].split('[')
    id = int(id)
    freq = {}
    for c in join:
        if c in freq: 
            freq[c] += 1
        else:
            freq[c] = 1
    lst = [(freq[key], key) for key in freq]
    lst.sort(key = lambda x: (-x[0],x[1]))
    checksum = ''.join([x[1] for x in lst[:5]])
    if checksum == given: count += id

print(count)
