#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int hb = (31 - __builtin_clz(n)), lb = 0, tot = 0;
    vector<int> ans;
    while (k > tot)
    {
        int v = 1 << (lb++);
        if (k > tot + v)
        {
            ans.push_back(v);
            tot += v;
        }
        else
        {
            int w = k - (v - 1) - 1;
            ans.push_back(w);
            break;
        }
    }
    if (k + 1 <= n)
    {
        ans.push_back(k + 1);
    }
    if (2 * k + 1 <= n)
    {
        ans.push_back(2 * k + 1);
    }
    if (3 * k + 1 <= n)
    {
        ans.push_back(3 * k + 1);
    }
    for (int i = lb; i <= hb; i++)
    {
        int v = 1 << (lb++);
        ans.push_back(v);
    }
    int sz = (int)ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++)
    {
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
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