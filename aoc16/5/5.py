import sys
import hashlib
ct = 0
given = 'cxdnnyjw'
password = ''

while len(password) < 8:
    m = hashlib.md5()
    m.update(bytes(given + str(ct), 'utf-8'))
    hash = m.hexdigest()
    if hash[:5] == '0'*5:
        password += hash[5]
        print(password)
    ct += 1


