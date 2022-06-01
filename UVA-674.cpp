#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 7490, M = 1e3 + 5, MOD = 32768, HV = 151, INF = 0x3f3f3f3f;
const int coin[] = {1, 5, 10, 25, 50};
int dp[N];

// dasdsa
void run()
{
    dp[0] = 1;
    for (int j = 0; j < 5; j++)
    {
        int jj = coin[j];
        for (int i = jj; i < N; i++)
        {
            dp[i] += dp[i - jj];
        }
    }
    int n;
    while (~scanf("%d", &n))
    {
        printf("%d\n", dp[n]);
    }
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