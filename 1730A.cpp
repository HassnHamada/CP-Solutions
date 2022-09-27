#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int frq[N];

void run()
{
    int n, c;
    scanf("%d%d", &n, &c);
    memset(frq, 0, sizeof(frq));
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        frq[v]++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += min(frq[i], c);
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
    {
        run();
    }
    return 0;
}