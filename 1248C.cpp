#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int fib[N], acc[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    fib[1] = fib[2] = 2;
    for (int i = 3; i < N; i++)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    for (int i = 1; i < N; i++)
    {
        acc[i] = (fib[i] + acc[i - 1]) % MOD;
    }
    printf("%d\n", (fib[n + 1] + acc[m - 1]) % MOD);
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}