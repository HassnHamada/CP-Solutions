#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 100, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int _div[N];
std::vector<int> prime;
bool is_composite[N];

void linear_sieve(int n)
{
    std::fill(is_composite, is_composite + n, false);
    std::fill(_div, _div + n, 1);
    for (int i = 2; i < n; ++i)
    {
        if (!is_composite[i])
            prime.push_back(i);
        for (int j = 0; j < (int)prime.size() && i * prime[j] < n; ++j)
        {
            is_composite[i * prime[j]] = true;
            _div[i * prime[j]] = i;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void get_pf(int n, vector<int> &out)
{
    while (n != 1)
    {
        out.push_back(n / _div[n]);
        n = _div[n];
    }
    sort(out.begin(), out.end());
}

void run()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    linear_sieve(N);
    vector<int> fct;
    get_pf(a, fct);
    get_pf(b, fct);
    for (int i = a + 1; i <= c; i++)
    {
        vector<int> tem;
        get_pf(i, tem);
        ll val = 1;
        int ii = 0, jj = 0;
        while (ii < (int)fct.size() && jj < (int)tem.size())
        {
            if (fct[ii] < tem[jj])
            {
                val *= fct[ii++];
            }
            else if (fct[ii] > tem[jj])
            {
                jj++;
            }
            else
            {
                ii++;
                jj++;
            }
        }
        while (ii < (int)fct.size())
        {
            val *= fct[ii++];
        }
        val = d / val * val;
        if (val > b && val <= d)
        {
            assert(i * val % (1ll * a * b) == 0);
            printf("%d %lld\n", i, val);
            return;
        }
    }
    printf("-1 -1\n");
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
