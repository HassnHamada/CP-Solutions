#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 31, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// ll arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> vec(M, 0);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        for (int i = 0; i < M; i++)
        {
            vec[i] += (v >> i) & 1;
        }
    }
    int ans = 0;
    for (int i = M - 1; ~i; i--)
    {
        if (vec[i] + k >= n)
        {
            ans += 1 << i;
            k -= n - vec[i];
            assert(k >= 0);
        }
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
