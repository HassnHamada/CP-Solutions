import sys
from queue import Queue


def main():
    inp = list()
    for i in range(3):
        inp.append("".join(input().split()))
    inp = "".join(inp)
    q: Queue[str] = Queue()
    ans: dict[str, int] = dict()
    q.put('123456789')
    ans['123456789'] = 0
    while not q.empty():
        s = q.get()
        for i in range(len(s)):
            for j in [1, -1, 3, -3]:
                if 0 <= i + j < len(s) and (i % 3 == (i + j) % 3 or i // 3 == (i + j) // 3):
                    t = list(s)
                    t[i], t[i + j] = t[i + j], t[i]
                    t = "".join(t)
                    if t not in ans:
                        ans[t] = ans[s] + 1
                        q.put(t)
    assert inp in ans
    print(ans[inp])


if __name__ == "__main__":
    with open("_input.txt", "r") as inf, open("_output.txt", "w") as outf:
        sys.stdin = inf
        sys.stdout = outf
        main()
