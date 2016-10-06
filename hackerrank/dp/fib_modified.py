import sys
for line in sys.stdin.readlines():
    a,b,n = [int(x) for x in line.split(" ")]

while n > 2:
    n -= 1
    c = a + b**2
    a = b
    b = c

print(c)

