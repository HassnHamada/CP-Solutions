#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 10, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

bool ok(int n, multiset<int, greater<int>> inp)
{
    while (n--)
    {
        while (!inp.empty() && (*inp.begin()) > (n + 1))
        {
            inp.erase(inp.begin());
        }
        if (inp.empty())
        {
            return false;
        }
        assert((*inp.begin()) <= (n + 1));
        inp.erase(inp.begin());
        if (!inp.empty())
        {
            int m = *inp.rbegin();
            inp.erase(inp.lower_bound(m));
            inp.insert(m + n + 1);
        }
    }
    return true;
}

void run()
{
    int n;
    scanf("%d", &n);
    multiset<int, greater<int>> inp;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        inp.insert(v);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ok(i + 1, inp) << " ";
    // }
    // cout << endl;
    int ans = 0;
    for (int i = 7; i--;)
    {
        if (ok(ans + (1 << i), inp))
        {
            ans += (1 << i);
        }
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
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
