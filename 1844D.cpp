#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char ans[N];

bool fill(int s, int e, char c, set<ll> &skip)
{
    bool done = true;
    for (int i = s; i < e; i++)
    {
        if (ans[i] == '?')
        {
            ans[i] = c;
            for (auto &&j : skip)
            {
                if (i + j > e)
                {
                    break;
                }
                if (ans[i + j] == '?')
                {
                    ans[i + j] = '\0';
                }
            }
        }
        else if (ans[i] == '\0')
        {
            ans[i] = '?';
            done = false;
        }
    }
    return done;
}

set<ll> fact(ll v)
{
    set<ll> ret = {1};
    for (ll i = 2; i * i <= v; i++)
    {
        if (v % i == 0)
        {
            ret.insert(i);
            ret.insert(v / i);
        }
    }
    ret.insert(v);
    return ret;
}

void run()
{
    int n;
    scanf("%d", &n);
    set<ll> skip = fact(n);
    memset(ans, '?', sizeof(ans[0]) * n);
    ans[n] = '\0';
    for (int i = 0; !fill(i, n, 'a' + i, skip); i++)
    {
        assert(i < 26);
    }
    printf("%s\n", ans);
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
