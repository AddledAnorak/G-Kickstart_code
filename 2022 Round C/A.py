t = int(input())

def solve():
    n = int(input())
    s = input()

    chk = False

    for i in range(65, 91):
        if(chr(i) in s):
            chk = True
            break
    
    if not chk:
        s += 'A'
    
    chk = False

    for i in range(97, 123):
        if(chr(i) in s):
            chk = True
            break
    
    if not chk:
        s += 'a'


    chk = False

    for i in range(48, 58):
        if(chr(i) in s):
            chk = True
            break
    
    if not chk:
        s += '0'

    if '#' not in s and '&' not in s and '@' not in s and '*' not in s:
        s += '#'
    
    while len(s) < 7:
        s += '1'
    
    return s


for i in range(t):
    print(f"Case #{i+1}: {solve()}")