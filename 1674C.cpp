#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 26, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char sss[N], ttt[N];

void run()
{
    scanf("%s%s", sss, ttt);
    int n = strlen(sss), m = strlen(ttt);
    int a = count(ttt, ttt + m, 'a');
    if (a)
    {
        if (m == 1)
        {
            printf("1\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    else
    {
        printf("%lld\n", 1ll << n);
    }
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
