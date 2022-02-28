import sys


def querie(i, j, k):
    print(f"? {i} {j} {k}")
    sys.stdout.flush()
    return int(input())


def try_next_ind(nxt, ans, ans_score):
    ii = querie(nxt, ans[1], ans[2])
    jj = querie(ans[0], nxt, ans[2])
    m = max(ii, jj, ans_score)
    if ii == m:
        ans = (nxt, ans[1], ans[2])
    elif jj == m:
        ans = (ans[0], nxt, ans[2])
    return (ans, m)


def magic_sort(i, j, k, l):
    ii = querie(j, k, l)
    jj = querie(i, k, l)
    kk = querie(i, j, l)
    ll = querie(i, j, k)
    m = max(ii, jj, kk, ll)
    if ii == jj == m:
        ans = (k, l, i)
    elif ii == kk == m:
        ans = (j, l, i)
    elif ii == ll == m:
        ans = (j, k, i)
    elif jj == kk == m:
        ans = (i, l, j)
    elif jj == ll == m:
        ans = (i, k, j)
    elif kk == ll == m:
        ans = (i, j, k)
    return (ans, m)


def run():
    n = int(input())
    ans, ans_score = magic_sort(*range(1, 5))
    for i in range(5, n + 1):
        ans, ans_score = try_next_ind(i, ans, ans_score)
    print(f"! {ans[0]} {ans[1]}")


def main():
    t = int(input())
    for _ in range(t):
        run()


if __name__ == "__main__":
    main()
