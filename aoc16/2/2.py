import sys

lines = []
for line in sys.stdin: 
    lines.append(line.strip())

at = (1,1)
valid = lambda pt: pt[0] >= 0 and pt[0] <= 2 and pt[1] >= 0 and pt[1] <= 2
dir = {key:value for key, value in zip('UDLR', [(0,-1),(0,1),(-1,0),(1,0)])}
keys = {key:value for key, value in [((x%3, x//3),x+1) for x in range(9)]}

for line in lines:
    for move in line:
        next = tuple(sum(x) for x in zip(at, dir[move]))
        if valid(next):
            at = next
    print(keys[at], end = "")

