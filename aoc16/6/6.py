import sys

lines = []
for line in sys.stdin: 
    lines.append(line.strip())

import collections
word = ''
for col in zip(*lines):
    ct = collections.Counter(col)
    word += ct.most_common(1)[0][0]
print(word)
