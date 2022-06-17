import sys


def run():
    _ = int(input())
    arr = sorted(map(int, input().split()))
    l = r = (0, 0)
    inl = set()
    for i in arr:
        if i == l[0] == r[0]:
            continue
        assert l[1] >= r[1]
        if l[1] == r[1]:
            l = (i, l[1]+1)
            inl.add(i)
        else:
            r = (i, r[1]+1)
            if i in inl:
                inl.remove(i)
    if r[1] < l[1] and len(inl):
        r = (l[0], r[1]+1)
    print(min(l[1], r[1]))


# with open("_input.txt", 'r') as fin, open("_output.txt", 'w') as fout:
#     sys.stdin = fin
#     sys.stdout = fout
t = int(input())
for _ in range(t):
    run()
