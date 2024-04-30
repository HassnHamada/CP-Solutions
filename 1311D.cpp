#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e4 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> prime;
bitset<N> is_composite;
int _div[N];

void sieve(int n)
{
    is_composite.reset();
    fill(_div, _div + n, 1);
    for (int i = 2; i < n; ++i)
    {
        if (!is_composite[i])
        {
            prime.push_back(i);
        }
        for (auto &&j : prime)
        {
            if (i * j >= n)
            {
                break;
            }
            is_composite[i * j] = true;
            _div[i * j] = i;
            if (i % j == 0)
            {
                break;
            }
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

void get_npf(int n, vector<int> &out)
{
    vector<int> pf;
    get_pf(n, pf);
    int m = pf.size();
    for (int i = 0; i < (1 << m); i++)
    {
        int v = 1;
        for (int j = 0; j < m; j++)
        {
            v *= (i & (1 << j) ? pf[j] : 1);
        }
        assert(v >= 1 && v <= n);
        out.push_back(v);
    }
    sort(out.begin(), out.end());
    out.erase(unique(out.begin(), out.end()), out.end());
    assert(out.front() == 1);
    assert(out.back() == n);
}

vector<int> np_div[N];

void pre()
{
    for (int i = 1; i < N; i++)
    {
        get_npf(i, np_div[i]);
    }
}

void run()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ll ans = 1ll * INF * INF;
    tuple<int, int, int> abc = {1, 1, 1};
    for (int i = 1; i < N; i++)
    {
        // cout << i << endl;
        for (auto &&j : np_div[i])
        {
            // cout << "\t" << j << endl;
            for (auto &&k : np_div[j])
            {
                ll v = 0ll + abs(c - i) + abs(b - j) + abs(a - k);
                if (v < ans)
                {
                    ans = v;
                    abc = {k, j, i}; 
                }
                // cout << "\t\t" << k << " " << v << endl;
            }
        }
    }
    printf("%lld\n", ans);
    printf("%d %d %d\n", get<0>(abc), get<1>(abc), get<2>(abc));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    sieve(N);
    pre();
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}