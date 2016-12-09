import sys

lines = []
for line in sys.stdin: 
    lines.append(line)
    break

moves = lines[0].split(', ')
dir = 0
"""
 0
3 1
 2
"""
x, y = 0, 0

for move in moves:
    if move[0] == 'R': dir += 1
    if move[0] == 'L': dir -= 1
    dir = (dir + 4) % 4
    if dir%2 == 0:
        y += int(move[1:]) * (1 - dir)
    else:
        x += int(move[1:]) * (2 - dir)

# print(x, y)
# print(abs(x) + abs(y))
