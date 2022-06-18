import sys

sys.stdin = open("_input.txt", "r")
sys.stdout = open("_output.txt", "w")

t = int(input())
for _ in range(t):
        
    n = int(input())
    s = input()
    # ans = list()
    def gen():
        o = z = 0
        for i, v in enumerate(s):
            if v == '0':
                if o:
                    yield i
                    # ans.append(i)
                    o = 0
                z += 1
            else:
                if z:
                    yield i
                    # ans.append(i)
                    z = 0
                o += 1
    print(n + sum(gen()))
