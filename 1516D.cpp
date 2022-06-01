#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int n, arr[N], nxt[N], acc[N], inn[N], per[N][M];
set<int> mempf[N];
bitset<N> prime;

void fastSieve(int n, vector<int> &vec)
{
    prime.set();
    for (ll i = 3; i * i <= n; i += 2)
    {
        for (ll j = i * i; prime[i / 2] && j <= n; j += 2 * i)
        {
            prime[j / 2] = 0;
        }
    }
    vec.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (prime[i / 2])
        {
            vec.push_back(i);
        }
    }
}

int nth_per(int c, int nn)
{
    assert(nn < (1 << M));
    for (int i = M - 1; ~i && c < n; i--)
    {
        if ((nn >> i) & 1)
        {
            c = per[c][i];
        }
    }
    return c;
}

void run()
{
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    vector<int> vec;
    fastSieve(N, vec);
    for (auto &&i : vec)
    {
        for (int j = i; j < N; j += i)
        {
            mempf[j].insert(i);
        }
    }

    int ii = 0, jj = 0;
    while (ii < n && jj < n)
    {
        for (auto &&i : mempf[arr[jj++]])
        {
            while (inn[i])
            {
                nxt[ii] = jj - 1;
                for (auto &&j : mempf[arr[ii++]])
                {
                    inn[j] = 0;
                }
            }
            inn[i] = 1;
        }
    }
    assert(jj == n);
    while (ii < n)
    {
        nxt[ii++] = n;
    }
    for (int i = 0; i < n; i++)
    {
        per[i][0] = nxt[i];
    }
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < n; j++)
        {
            per[j][i] = per[j][i - 1] < n ? per[per[j][i - 1]][i - 1] : n;
        }
    }
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int s = 0, e = (1 << M) - 1;
        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (nth_per(l - 1, m) >= r)
            {
                e = m;
            }
            else
            {
                s = m + 1;
            }
        }
        printf("%d\n", e);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}