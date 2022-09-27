#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e9, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int inp[N];
// int inp[N], dp[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", inp + i);
    }
    // inp[k] = 0;
    ll v = inp[k];
    ll lv = v, li = k;
    ll rv = v, ri = k;
    while (true)
    {
        // cout << k << " " << v << endl;
        assert(lv >= 0);
        assert(rv >= 0);
        while (li > 1)
        {
            lv += inp[--li];
            if (lv < 0 || lv > v)
            {
                break;
            }
        }
        while (ri < n)
        {
            rv += inp[++ri];
            if (rv < 0 || rv > v)
            {
                break;
            }
        }
        // cout << li << " " << lv << " " << ri << " " << rv << endl;
        if (rv < 0 && lv < 0)
        {
            printf("NO\n");
            break;
        }
        else if (rv < 0 || lv < 0)
        {
            if (rv < 0)
            {
                rv += lv - v;
                rv -= inp[ri--];
                v = lv;
                // k = li;
            }
            else
            {
                lv += rv - v;
                lv -= inp[li++];
                v = rv;
                // k = ri;
            }
        }
        else if (rv >= 0 && lv >= 0)
        {
            v = rv = lv = rv + lv - v;
            // if (lv > rv)
            // {
            //     v = lv;
            //     k = li;
            // }
            // else
            // {
            //     lv += rv - v;
            //     v = rv;
            //     k = ri;
            // }
        }
        else
        {
            assert(false);
        }
        if (li == 1 || ri == n)
        {
            printf("YES\n");
            break;
        }
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