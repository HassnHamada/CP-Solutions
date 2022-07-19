#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 26, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

pair<int, pair<int, int>> work(vector<int> &vec)
{
    int fn = -1, ln = -1, ret = 0, n = 0, ft = 0, lt = 0;
    for (int i = 0; i < (int)vec.size(); i++)
    {
        if (fn == -1)
        {
            ft += abs(vec[i]) == 2;
        }
        if (vec[i] < 0)
        {
            if (fn == -1)
            {
                fn = i;
            }
            ln = i;
            lt = 0;
            n += 1;
        }
        if (ln != -1)
        {
            lt += abs(vec[i]) == 2;
        }
        ret += abs(vec[i]) == 2;
    }
    if (n & 1)
    {
        if (ft < lt)
        {
            return {ret - ft, {fn + 1, 0}};
        }
        return {ret - lt, {0, vec.size() - ln}};
    }
    return {ret, {0, 0}};
}

void run()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> vec;
    vec.emplace_back();
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        if (v == 0)
        {
            vec.emplace_back();
            continue;
        }
        vec.back().push_back(v);
    }
    int ans = -INF, x = n, y = 0, cx = 0;
    for (auto &&i : vec)
    {
        auto res = work(i);
        if (res.first > ans)
        {
            ans = res.first;
            x = cx + res.second.first;
            y = n - cx - (int)i.size() + res.second.second;
        }
        cx += i.size() + 1;
    }
    printf("%d %d\n", x, y);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
