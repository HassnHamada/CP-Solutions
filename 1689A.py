
t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    aaa, bbb = list(input()), list(input())
    ansa, ansb = list(), list()
    for i in range(k):
        if i % 2 == 0:
            ansa.append(min(aaa))
            ansb.append(min(bbb))
        else:
            ansa.append(min(bbb))
            ansb.append(min(aaa))
        aaa.remove(min(aaa))
        bbb.remove(min(bbb))
        if len(aaa) == 0 or len(bbb) == 0:
            break
    
    print(ansa if ansa < ansb else ansb)
