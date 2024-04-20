#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

bool bf(int n, int s, int u, vector<int> &ans)
{
    assert(n < 10);
    if (u + 1 == (1 << n))
    {
        return true;
    }
    int v = ans.empty() ? -1 : ans.back();
    for (int i = 0; i < n; i++)
    {
        bool ok = v == -1 || (abs(i + s + 1 - v) >= 2 && abs(i + s + 1 - v) <= 4);
        if (ok && !(u & (1 << i)))
        {
            ans.push_back(i + s + 1);
            if (bf(n, s, u | (1 << i), ans))
            {
                return true;
            }
            ans.pop_back();
        }
    }
    return false;
}

void run()
{
    int n;
    scanf("%d", &n);
    vector<int> ans;
    int s = 0;
    while (n >= 10)
    {
        ans.push_back(1 + s);
        ans.push_back(3 + s);
        ans.push_back(5 + s);
        ans.push_back(2 + s);
        ans.push_back(4 + s);
        n -= 5;
        s += 5;
    }
    if (bf(n, s, 0, ans))
    {
        for (int i = 0; i < n - 1; i++)
        {
            assert(abs(ans[i] - ans[i + 1]) >= 2 && abs(ans[i] - ans[i + 1]) <= 4);
        }

        for (int x : ans)
        {
            printf("%d%c", x, " \n"[x == ans.back()]);
        }
    }
    else
    {
        printf("-1\n");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}