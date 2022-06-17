class BIT():
    def __init__(self, n) -> None:
        self.n = n
        self.arr = [0] * self.n

    def add(self, i, v) -> None:
        i += 1
        while i <= self.n:
            self.arr[i-1] += v
            i += i & -i

    def get(self, i) -> int:
        i += 1
        ret = 0
        while i:
            ret += self.arr[i-1]
            i -= i & -i
        return ret

    def clear(self):
        self.arr = [0] * self.n


t = int(input())
for _ in range(t):
    n = int(input())
    bit = BIT(n+1)
    arr = map(int, input().split())
    ans = 0
    for i in arr:
        if bit.get(n) - bit.get(i) != 0:
            ans += 1
            bit.clear()
        else:
            bit.add(i, 1)
    print(ans)
