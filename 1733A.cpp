#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

const int N = 1e2 + 10, M = 26, L = 4, MOD = 9, HV = 151, INF = 0x3f3f3f3f;

int inp[N], idx[N];
vector<int> arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        arr[i].clear();
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", inp + i);
        arr[(i + 1) % k].push_back(inp[i]);
    }
    for (int i = 0; i < k; i++)
    {
        sort(arr[i].begin(), arr[i].end(), greater<int>());
    }
    ll ans = 0;
    for (int i = 0; i <= n - k; i++)
    {
        ll tem = 0;
        memset(idx, 0, sizeof(idx));
        for (int j = 0; j < k; j++)
        {
            tem += arr[(i + j + 1) % k][idx[(i + j + 1) % k]++];
        }
        ans = max(ans, tem);
    }
    printf("%lld\n", ans);
    // printf("%s\n", ans[solve(0, n - 1)]);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}