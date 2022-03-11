#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 5e3 + 10;
int arr[N], dp[N][N], n, x;

int asd(int i, int k)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }
    return dp[i][k] = max({k ? arr[i] + x + asd(i + 1, k - 1) : 0,
                           arr[i] + asd(i + 1, k), 0});
}

void run()
{
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++)
    {
        memset(dp + i, -1, sizeof(int) * (n + 1));
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i <= n; i++)
    {
        int mx = 0;
        for (int j = 0; j < n; j++)
        {
            mx = max(mx, asd(j, i));
        }
        printf("%d%c", mx, " \n"[i == n]);
    }
}

int main(int argc, char const *argv[])
{
    // freopen("./_input.txt", "r", stdin);
    // freopen("./_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
