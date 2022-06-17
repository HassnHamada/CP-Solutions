#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
// int sss[N], fff[N], ans[N];
int acc[N];

void run()
{
    int n, k;
    scanf("%d%d\n", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        char c;
        scanf("%c", &c);
        // cout << c << endl;
        acc[i] = (int)(c == 'W');
    }
    for (int i = 1; i <= n; i++)
    {
        acc[i] += acc[i - 1];
    }
    int mn = INF;
    for (int i = k; i <= n; i++)
    {
        mn = min(mn, acc[i] - acc[i - k]);
    }
    printf("%d\n", mn);
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
