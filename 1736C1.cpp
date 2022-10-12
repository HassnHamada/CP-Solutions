#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 10, M = 3e5, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N], ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        arr[i] -= i;
        ans[i] = n + 1;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && arr[i] <= -q.front())
        {
            ans[q.front()] = i;
            q.pop();
        }
        q.push(i);
    }

    ll _ans = 0;
    for (int i = 1; i <= n; i++)
    {
        _ans += ans[i] - i;
    }
    printf("%lld\n", _ans);
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