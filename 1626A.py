from string import ascii_lowercase

t = int(input())
for _ in range(t):
    s = input()
    f = dict(zip(ascii_lowercase, [0] * 26))
    for i in s:
        f[i] += 1
    f = list((i, j) for i, j in f.items())
    ans = list()
    for l, v in f:
        assert v < 3
        if v != 2:
            continue
        ans.append(l)
    for l, v in f:
        if v != 2:
            continue
        ans.append(l)
    for l, v in f:
        if v != 1:
            continue
        ans.append(l)
    print("".join(ans))
