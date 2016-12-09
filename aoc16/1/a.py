import sys

lines = []
for line in sys.stdin: 
    lines.append(line)
    break
n, a, b, c = [int(x) for x in lines[0].split()]

cheap = float('inf')
cost = [a,b,c]

def ways(n, k, c, added):
    global cheap
    if n % 4 == 0: 
        cheap = min(cheap, c)
    elif added > 4 or k < 0:
        pass
    else:
        ways(n + k + 1, k, c + cost[k], added + 1)
        ways(n, k-1, c, added)

ways(n, 2, 0, 0)
print(cheap)
