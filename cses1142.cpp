#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], nxt[N], prv[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    stack<int> stk;
    for (int i = 1; i <= n; i++)
    {
        while (!stk.empty() && arr[stk.top()] > arr[i])
        {
            nxt[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        nxt[stk.top()] = n + 1;
        stk.pop();
    }

    for (int i = n; i; i--)
    {
        while (!stk.empty() && arr[stk.top()] > arr[i])
        {
            prv[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        prv[stk.top()] = 0;
        stk.pop();
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, arr[i] * (nxt[i] - prv[i] - 1ll));
    }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}