#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 1e9, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int inp[N];
vector<ll> fib, acc;

void run()
{
    int k;
    scanf("%d", &k);
    ll sum = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", inp + i);
        sum += inp[i];
    }
    bool ok = true;
    auto ii = find(acc.begin(), acc.end(), sum);
    if (ii == acc.end())
    {
        ok = false;
    }
    if (ok)
    {
        for (int i = ii - acc.begin(), l = -1; ~i; i--)
        {
            int mx = *max_element(inp, inp + k);
            if (mx < fib[i])
            {
                ok = false;
                break;
            }
            int nl = -1;
            for (int j = 0; j < k; j++)
            {
                if (inp[j] == mx && j != l)
                {
                    nl = j;
                    break;
                }
            }
            if (nl == -1)
            {
                ok = false;
                break;
            }
            inp[l = nl] -= fib[i];
        }
    }
    if (ok)
    {
        assert(all_of(inp, inp + k, [](int i)
                      { return i == 0; }));
    }
    printf(ok ? "YES\n" : "NO\n");
}

void pre()
{
    for (int i = 0, j = 1; j <= M; j += i)
    {
        fib.push_back(j);
        swap(i, j);
    }
    acc.push_back(1);
    for (int i = 1; i < (int)fib.size(); i++)
    {
        acc.push_back(acc[i - 1] + fib[i]);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    pre();
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}