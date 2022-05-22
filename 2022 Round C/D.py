t = int(input())

mem = {
    "": 1
}

isPalindrome = lambda s: s == s[::-1]

def get_answer(p, q):
    x = 1
    i = 1
    while True:
        if p+i*1000000007 % q == 0:
            x = (p+i*1000000007) / q
            break

        i += 1
    return x


def dfs(s):
    if s in mem:
        return mem[s]

    sum_ = 0

    if isPalindrome(s):
        sum_ += 1

    for i in range(len(s)):
        sum_ += dfs(s[0:i] + s[i+1:])
    
    mem[s] = sum_
    return sum_



def solve():
    n = int(input())
    s = input()

    sum_ = dfs(s)

    return get_answer(sum_, len(s))



for i in range(t):
    print(f"Case #{i+1}: {solve()}")