#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10, M = 1e7 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

vector<int> prime;
bitset<M> is_composite;
int _div[M];

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

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    vector<pair<int, int>> ans(n, {-1, -1});
    for (int i = 0; i < n; i++)
    {
        vector<int> div;
        get_pf(arr[i], div);
        fprintf(stderr, "Divisors of %d (%d)\n", arr[i], (int)div.size());
        for (auto &&j : div)
        {
            fprintf(stderr, "%d%c", j, " \n"[j == div.back()]);
        }
        int sz = (int)div.size();
        for (int j = 1, d1 = div[0]; j < sz; d1 *= div[j++])
        {
            int d2 = arr[i] / d1;
            if (gcd(d1 + d2, arr[i]) == 1)
            {
                assert(arr[i] % d1 == 0);
               assert(arr[i] % d2 == 0);
                ans[i] = {d1, d2};
                break;
            } 
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d%c", (i ? ans[j].second : ans[j].first), " \n"[j == n - 1]);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    sieve(M);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}