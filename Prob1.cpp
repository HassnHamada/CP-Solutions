#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N][N];

ll sum(vector<int> &vec)
{
    ll ret = 0;
    for (auto &&i : vec)
    {
        ret += i;
    }
    return ret;
}

ll inter(vector<int> &a, vector<int> &b)
{
    ll ret = 0;
    set<int> s(a.begin(), a.end());
    for (auto &&i : b)
    {
        if (s.find(i) == s.end())
        {
            continue;
        }
        ret += 1;
    }
    return ret;
}
void run()
{
    // O((n*m!/(n*m-m)!/m!) * ((n*m-m)!/(n*m-m-n+1)!/(n-1)!))
    // Input n, m, x, y
    // Output n row each row contains m element where the sum of the xth row is equal to the sum of the yth column 
    // Each number from 1 to n*m must appear once
    // 1 <= n <= 1000
    // 1 <= m <= 1000
    // 1 <= x <= n
    // 1 <= y <= m
    // Solution O(n*m*log(n*m))
    // The question can be rephrased to from numbers [1, m*m] 
    // choose n distinct number call it set A
    // and choose m distinct number call it set B
    // We need two sets where the sum of A equals the sum of B
    // and A intersects B at exactly one elemnt
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    if (n == 1 && m == 1)
    {
        printf("1\n");
        return;
    }
    if (n == 1 || m == 1 || (n == 2 && m == 2))
    {
        printf("-1\n");
        return;
    }
    set<int> nums;
    for (int i = 1; i <= n * m; i++)
    {
        nums.insert(i);
    }
    bool ok = true;
    int v = min(n, m), w = max(n, m);
    vector<int> aaa, bbb;
    if (w > v)
    {
        int t = 0;
        for (int j = 0; j < v; j++)
        {
            aaa.push_back(*nums.rbegin());
            nums.erase(aaa.back());
            t += aaa.back();
            for (int i = bbb.size(); i < w - v + j; i++)
            {
                bbb.push_back(*nums.begin());
                nums.erase(nums.begin());
                t -= bbb.back();
            }
            assert(t < n * m - j || t > n * m);
            auto it = nums.find(t);
            if (it != nums.end())
            {
                bbb.push_back(*it);
                nums.erase(it);
                break;
            }
            if (j + 1 == v)
            {
                ok = false;
            }
        }
        if (ok)
        {
            assert(v - aaa.size() == w - bbb.size());
            v -= aaa.size();
            w -= bbb.size();
        }
    }
    else
    {
        bbb.push_back(1);
        nums.erase(1);
        aaa.push_back(2);
        nums.erase(2);
        aaa.push_back(3);
        nums.erase(3);
        bbb.push_back(4);
        nums.erase(4);
        v -= 2;
        w -= 2;
    }
    if (ok && v)
    {
        // cout << "--------- " << v << endl;
        if (v & 1)
        {
            aaa.push_back(*nums.begin());
            bbb.push_back(*nums.begin());
            nums.erase(nums.begin());
            v -= 1;
        }
        else
        {
            bool tem = false;
            for (auto i = bbb.rbegin(); i != bbb.rend(); i++)
            {
                int j = *i;
                if (nums.find(j + 1) != nums.end() &&
                    nums.find(j + 2) != nums.end() &&
                    nums.find(j + 3) != nums.end())
                {
                    aaa.push_back(j);
                    bbb.push_back(j + 1);
                    nums.erase(j + 1);
                    bbb.push_back(j + 2);
                    nums.erase(j + 2);
                    aaa.push_back(j + 3);
                    nums.erase(j + 3);
                    tem = true;
                    break;
                }
            }
            assert(tem);
            v -= 2;
        }
        vector<int> stk;
        for (; v; v -= 2)
        {
            while (true)
            {
                do
                {
                    assert(!nums.empty());
                    stk.push_back(*nums.begin());
                    nums.erase(nums.begin());
                } while (stk.size() < 4);
                if (stk[stk.size() - 4] + 3 == stk.back())
                {
                    aaa.push_back(stk.back());
                    stk.pop_back();
                    bbb.push_back(stk.back());
                    stk.pop_back();
                    bbb.push_back(stk.back());
                    stk.pop_back();
                    aaa.push_back(stk.back());
                    stk.pop_back();
                    break;
                }
            }
        }
        while (stk.size())
        {
            nums.insert(stk.back());
            stk.pop_back();
        }
        sort(aaa.begin(), aaa.end());
        sort(bbb.begin(), bbb.end());
        assert((int)aaa.size() == min(n, m));
        assert((int)bbb.size() == max(n, m));
        assert((int)nums.size() == n * m - n - m + 1);
        assert(inter(aaa, bbb) == 1);
        assert(sum(aaa) == sum(bbb));
        assert(set<int>(aaa.begin(), aaa.end()).size() == aaa.size());
        assert(set<int>(bbb.begin(), bbb.end()).size() == bbb.size());
        // for (auto &&i : aaa)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (auto &&i : bbb)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (auto &&i : nums)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        if (n < m)
        {
            swap(aaa, bbb);
        }
        int c = -1;
        for (int i = 1; i <= m; i++)
        {
            if (i == y)
            {
                continue;
            }
            auto it = lower_bound(bbb.begin(), bbb.end(), aaa.back());
            if (it != bbb.end() && *it == aaa.back())
            {
                assert(c == -1);
                c = aaa.back();
                aaa.pop_back();
            }
            ans[x][i] = aaa.back();
            aaa.pop_back();
        }
        assert(aaa.empty() || c == -1);
        if (c == -1)
        {
            assert(aaa.size() == 1);
            auto it = lower_bound(bbb.begin(), bbb.end(), aaa.back());
            assert(it != bbb.end() && *it == aaa.back());
            c = aaa.back();
            aaa.pop_back();
        }
        assert(aaa.empty());
        assert(c != -1);
        for (int i = 1; i <= n; i++)
        {
            if (i == x)
            {
                continue;
            }
            if (bbb.back() == c)
            {
                bbb.pop_back();
            }
            ans[i][y] = bbb.back();
            bbb.pop_back();
        }
        assert(bbb.empty() || (bbb.size() == 1 && bbb[0] == c));

        ans[x][y] = c;
        for (int i = 1; i <= n; i++)
        {
            if (i == x)
            {
                continue;
            }
            for (int j = 1; j <= m; j++)
            {
                if (j == y)
                {
                    continue;
                }
                assert(ans[i][j] == 0);
                assert(!nums.empty());
                ans[i][j] = *nums.begin();
                nums.erase(nums.begin());
            }
        }
        assert(nums.empty());
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                printf("%d%c", ans[i][j], " \n"[j == m]);
            }
        }
    }
    else
    {
        printf("-1\n");
    }
}

int main()
{
    freopen("magic.in", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}


// test.py
// from collections import Counter
// from functools import reduce
// from itertools import combinations, combinations_with_replacement
// from os import system
// from random import randint, choice
// import sys
// from time import perf_counter_ns

// stdout = sys.stdout
// stdin = sys.stdin

// N = 1000

// while True:
//     with open("_input.txt", "w") as fout:
//         sys.stdout = fout
//         n, m = randint(1, N), randint(1, N)
//         x, y = randint(1, n), randint(1, m)
//         print(n, m, x, y)

//     # system("_ok.exe")
//     tic = perf_counter_ns()
//     system("_out.exe")
//     toc = perf_counter_ns()

//     # with open("_output.txt", "r") as bad, open("_ok.txt", "r") as ok:
//     #     sys.stdout = stdout
//     #     for i, (l1, l2) in enumerate(zip(bad, ok)):
//     #         try:
//     #             assert l1 == l2
//     #         except AssertionError:
//     #             raise AssertionError(f"{i + 1}\n\t{l1}\t{l2}")
//     #     for l in bad:
//     #         assert False
//     #     for l in ok:
//     #         assert False

//     print(f"DONE in {(toc-tic)//1000000}ms", file=stdout)
//     assert (toc-tic)//1000000 < 1000

//     with open("_output.txt", "r") as fin:
//         sys.stdin = fin
//         sys.stdout = stdout
//         res = input()
//         if len(res) == 2:
//             res = int(res)
//             assert res == -1
//             # l = set(range(1, n * m + 1))
//             # for i in combinations(l, n):
//             #     i = set(i)
//             #     s = sum(i)
//             #     for j in combinations(l - i, m - 1):
//             #         j = sum(j)
//             #         assert j >= s or s - j not in i
//         else:
//             mat = [list(map(int, res.split()))]
//             mat.extend(list(list(map(int, input().split()))
//                        for _ in range(n - 1)))
//             assert sum(mat[x-1]) == sum(mat[i][y-1] for i in range(n))
//             assert all(1 <= j <= n * m for i in mat for j in i)
//             assert Counter(j for i in mat for j in i).most_common(1)[0][1] == 1
//     # break
