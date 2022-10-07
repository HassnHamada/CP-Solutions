#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e2 + 10, M = 128, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

char str[N], ans[N];
int frq[M];

void run()
{
    memset(frq, 0, sizeof(frq));
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
    {
        frq[(int)str[i]]++;
    }
    for (int i = 0, j = 'a', l = 0; i < k; i++, j = 'a', l = 0)
    {
        while (frq[j] && l < n / k)
        {
            frq[j++]--;
            l += 1;
        }
        ans[i] = (char)j;
    }
    ans[k] = '\0';
    printf("%s\n", ans);
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