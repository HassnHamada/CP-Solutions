#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 31, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n;
    scanf("%d", &n);
    vector<int> sz(n);
    for (int i = 0, v; i < n - 1; i++)
    {
        scanf("%d", &v);
        sz[--v]++;
    }
    sz.push_back(1);
    sort(sz.begin(), sz.end(), greater<int>());
    while (!sz.empty() && sz.back() <= 0)
    {
        sz.pop_back();
    }
    n = sz.size();
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        sz[i] = sz[i] - n + i;
    }
    sort(sz.begin(), sz.end(), greater<int>());
    while (!sz.empty() && sz.back() <= 0)
    {
        sz.pop_back();
    }
    while (!sz.empty())
    {
        for (auto &&i : sz)
        {
            i -= 1;
        }
        sz[upper_bound(sz.begin(), sz.end(), sz[0], greater<int>()) - sz.begin() - 1] -= 1;
        while (!sz.empty() && sz.back() <= 0)
        {
            sz.pop_back();
        }
        ans += 1;
    }
    printf("%d\n", ans);
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
