import sys

def scan():
    return input().rstrip().split()

def scan_numeric():
    return [(int(x) if float(x).is_integer() else float(x)) for x in scan()]

N, M = scan_numeric()
flowers = scan_numeric()
subs = []
for i in range(M):
    subs.append(scan_numeric())

dp = [0]

for i in range(N): dp.append(flowers[i] + dp[i])

happiness = 0
for i in range(M):
    l, r = subs[i]
    add = dp[r] - dp[l-1]
    if add > 0: happiness += add

print(happiness)
