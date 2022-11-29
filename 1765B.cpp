#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char inp[N];

void run()
{
    int n;
    scanf("%d%s", &n, inp);
    bool ok = true;
    for (int i = 0, p = 0; ok && i < n; i += 1 + p, p ^= 1)
    {
        if (p)
        {
            ok = i + 1 < n && inp[i] == inp[i + 1];
        }
    }
    printf(ok ? "YES\n" : "NO\n");
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