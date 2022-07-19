#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int mn = -INF, mx = INF;
    while (k--)
    {
        int j = k + 1;
        int cmn = arr[n - 1] / j, cmx = cmn;
        for (int i = n - 2; ~i; i--)
        {
            int v = arr[i] / j;
            int vmn = min(cmn, v), vmx = max(cmx, v);
            while (j > 1)
            {
                int w = arr[i] / (j - 1);
                int wmn = min(cmn, w), wmx = max(cmx, w);
                if (wmx - wmn > vmx - vmn)
                {
                    break;
                }
                if (wmx - wmn == vmx - vmn && wmx >= vmx)
                {
                    break;
                }
                vmn = wmn;
                vmx = wmx;
                j -= 1;
            }
            cmn = vmn;
            cmx = vmx;
        }
        if (cmx - cmn < mx - mn)
        {
            mn = cmn;
            mx = cmx;
        }
    }
    printf("%d\n", mx - mn);
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}