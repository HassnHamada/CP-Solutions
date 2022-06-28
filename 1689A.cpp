#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e2 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char aaa[N], bbb[N], ccc[N];

void run()
{
    int n, m, k;
    scanf("%d%d%d%s%s", &n, &m, &k, aaa, bbb);
    sort(aaa, aaa + n);
    sort(bbb, bbb + m);
    int ii = 0, jj = 0, kk = 0, a = 0, b = 0;
    while (ii < n && jj < m)
    {
        if (a == k)
        {
            ccc[kk++] = bbb[jj++];
            a = 0;
            b = 1;
            continue;
        }
        if (b == k)
        {
            ccc[kk++] = aaa[ii++];
            a = 1;
            b = 0;
            continue;
        }
        if (aaa[ii] < bbb[jj])
        {
            ccc[kk++] = aaa[ii++];
            a += 1;
            b = 0;
        }
        else
        {
            ccc[kk++] = bbb[jj++];
            a = 0;
            b += 1;
        }
    }
    ccc[kk] = '\0';
    printf("%s\n", ccc);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d"/, &n), n)
    {
        run();
    }

    return 0;
}
