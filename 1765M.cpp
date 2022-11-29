#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e2 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

void run()
{
    int n;
    scanf("%d", &n);
    int i = 2;
    for (; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            break;
        }
    }
    if (n % i)
    {
        printf("1 %d\n", n - 1);
    }
    else
    {
        printf("%d %d\n", n / i, n - n / i);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}