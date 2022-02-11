t = int(input())
for _ in range(t):
    s = list(input())
    n = len(s)
    d = False
    for i in range(n - 1, 0, -1):
        v = int(s[i]) + int(s[i - 1])
        if v >= 10:
            s[i] = str(v % 10)
            s[i - 1] = str(v // 10)
            d = True
            break
    # 1 2 3 4 5 6
    #     ^
    if not d:
        for i in range(n - 1):
            v = int(s[i]) + int(s[i + 1])
            if v > int(s[i]) or i == n - 2:
                ns = s[:i]
                ns.append(str(v))
                ns.extend(s[i + 2:])
                s = ns
                break

    print("".join(s))
