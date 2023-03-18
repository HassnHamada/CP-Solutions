#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char inp[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int mn = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", inp);
        int o = count(inp, inp + m, '1'), oo = 0, k = 0, l = 0;
        for (int j = 1; j < m; j++)
        {
            if (inp[j] == '1' && inp[j - 1] == '1')
            {
                oo++;
                j++;
            }
        }
        for (int j = 1; j < m; j++)
        {
            if (inp[j] == '1' && inp[j - 1] == '1')
            {
                l += (j - k) / 2;
                k = j;
            }
        }
        l += (m - k) / 2;
        mn += o - min(oo, m / 4);
        mx += o - max(m / 4 - l, 0);
    }
    printf("%d %d\n", mn, mx);
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}