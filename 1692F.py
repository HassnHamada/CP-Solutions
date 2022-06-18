from collections import Counter
# import sys

# sys.stdin = open("_input.txt", "r")
# sys.stdout = open("_output.txt", "w")


t = int(input())
for _ in range(t):
    n = int(input())
    # n, k = map(int, input().split())
    inp = Counter(map(lambda x: int(x) % 10, input().split()))
    ok = False
    for i in inp:
        tem = Counter(inp)
        tem[i] -= 1
        if tem[i] == 0:
            tem.pop(i)
        for j in tem:
            tem2 = Counter(tem)
            tem2[j] -= 1
            if tem2[j] == 0:
                tem2.pop(j)
            for k in tem2:
                if (i + j + k) % 10 == 3:
                    ok = True
    print("YES" if ok else "NO")
