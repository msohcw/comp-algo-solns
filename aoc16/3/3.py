import sys

lines = []
for line in sys.stdin: 
    lines.append(line.strip())

count = 0

for line in lines:
    sides = [int(x) for x in line.split()]
    sides.sort()
    if sides[0] + sides[1] > sides[2]: count += 1

print(count)
