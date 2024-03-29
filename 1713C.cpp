#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, L = 4, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int ans[N];

// r = 4, s = 4
void recurse(int r)
{
    if (r < 0)
        return;
    int s = 0;
    while (s * s < r)
    {
        s += 1;
    }
    s *= s;
    int l = s - r;
    for (; l <= r; l++, r--)
    {
        ans[l] = r;
        ans[r] = l;
    }
    recurse(l - 1);
}

void run()
{
    int n;
    scanf("%d", &n);
    recurse(n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
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
