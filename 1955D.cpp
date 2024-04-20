#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
map<int, int> frq;

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0, v; i < m; i++)
    {
        scanf("%d", &v);
        frq[v]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (frq[arr[i]]-- > 0)
        {
            k -= 1;
        }
    }
    int ans = k <= 0;
    for (int i = m; i < n; i++)
    {
        if (++frq[arr[i - m]] > 0)
        {
            k += 1;
        }
        if (frq[arr[i]]-- > 0)
        {
            k -= 1;
        }
        ans += k <= 0;
    }
    printf("%d\n", ans);
    frq.clear();
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