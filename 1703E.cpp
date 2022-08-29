#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 64, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char arr[N][N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(arr + i));
    }
    int ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int v = arr[i][j] - '0' +
                    arr[n - j - 1][i] - '0' +
                    arr[n - i - 1][n - j - 1] - '0' +
                    arr[j][n - i - 1] - '0';
            // cout << v << endl;
            ans += min(v, 4 - v);
        }
    }
    if (n & 1)
    {
        for (int i = 0; i < n / 2; i++)
        {
            int v = arr[n / 2][i] - '0' +
                    arr[n / 2][n - i - 1] - '0' +
                    arr[i][n / 2] - '0' +
                    arr[n - i - 1][n / 2] - '0';
            ans += min(v, 4 - v);
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