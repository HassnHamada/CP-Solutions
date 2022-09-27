#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e2 + 10, M = 1e9, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int inp[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", inp + i);
    }
    sort(inp, inp + n);
    int ans = INT32_MAX;
    for (int i = 1; i < n - 1; i++)
    {
        ans = min(ans, inp[i + 1] - inp[i - 1]);
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