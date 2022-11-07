#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 14, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

bitset<N> dp;

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> vec(k);
    for (auto &&i : vec)
    {
        scanf("%d", &i);
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= n; i++)
    {
        for (auto &&j : vec)
        {
            if (j > i)
            {
                break;
            }
            if (dp[i - j] == 0)
            {
                dp[i] = 1;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf(dp[i] ? "W" : "L");
    }
    printf("\n");
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}