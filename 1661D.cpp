#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 5, MOD = 32768, HV = 151, INF = 0x3f3f3f3f;
ll arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    ll ans = 0, dec = 0, tot = 0;
    queue<pair<ll, int>> q;
    for (int i = n - 1; i >= 0; i--)
    {
        tot -= dec;
        while (!q.empty() && q.front().second == i)
        {
            dec -= q.front().first;
            q.pop();
        }
        arr[i] -= tot;
        if (arr[i] > 0 && i >= k)
        {
            ll v = (arr[i] + k - 1) / k;
            ans += v;
            dec += v;
            tot += v * k;
            q.push({v, i - k});
        }
    }
    ll mx = 0;
    for (int i = 0; i < k; i++)
    {
        mx = max(mx, ((arr[i] + i) / (i + 1)));
    }
    printf("%lld\n", ans + mx);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}