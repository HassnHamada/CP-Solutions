from collections import Counter
import sys


def run():
    _ = int(input())
    arr = list(map(int, input().split()))
    counter = Counter(arr)
    nxt = 0
    ans = list()
    sss = set()
    for i in arr:
        if i >= nxt:
            sss.add(i)
        while nxt in sss:
            sss.remove(nxt)
            nxt += 1
        counter[i] -= 1
        if counter[i] == 0:
            counter.pop(i)
        if nxt not in counter:
            ans.append(nxt)
            sss.clear()
            nxt = 0
    print(len(ans))
    print(*ans)


# with open("_input.txt", 'r') as fin, open("_output.txt", 'w') as fout:
#     sys.stdin = fin
#     sys.stdout = fout
t = int(input())
for _ in range(t):
    run()
