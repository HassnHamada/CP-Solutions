#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e2 + 10, M = 2, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

char str[N];

void run()
{
    int n;
    scanf("%d%s", &n, str);
    int q = 0;
    for (int i = 0; str[i]; i++)
    {
        q += str[i] == 'Q' ? 1 : -1;
        q = max(q, 0);
    }
    printf(q == 0 ? "Yes\n" : "No\n");
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