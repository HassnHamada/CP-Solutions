from queue import Queue
x0, y0, x1, y1 = map(int, input().split())
sp, ep = (x0, y0), (x1, y1)
n = int(input())
grd = set()
for _ in range(n):
    r, a, b = map(int, input().split())
    for i in range(a, b+1):
        grd.add((r, i))

assert sp in grd
assert ep in grd

dis = {sp: 0}
q = Queue(len(grd))
q.put(sp)

while not q.empty():
    t = q.get()
    tx, ty = t
    for i in range(-1, 2):
        for j in range(-1, 2):
            np = (tx + i, ty + j)
            if np in dis or np not in grd:
                continue
            dis[np] = dis[t] + 1
            q.put(np)


print(dis.get(ep, -1))
