#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N];

bitset<N> prime;

void sieve(int n, vector<int> &vec, vector<int> &non)
{
    for (int i = 1; i <= n; i++)
    {
        prime.set(i);
    }
    for (ll i = 2; i * i <= n; i++)
    {
        for (ll j = i * i; prime[i] && j <= n; j += i)
        {
            prime[j] = 0;
        }
    }
    non.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        (prime[i] ? vec : non).push_back(i);
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    vector<int> primes, non;
    sieve(n, primes, non);
    int l = 0, r = n - 1, p = 0;
    for (int i = 0; i < (int)primes.size(); i++, p ^= 1)
    {
        if (p)
        {
            ans[r--] = primes[i];
        }
        else
        {
            ans[l++] = primes[i];
        }
    }
    assert(r - l + 1 == (int)non.size());
    for (int i = 1; i <= (int)non.size(); i++, p ^= 1)
    {
        if (p)
        {
            ans[r--] = non[(int)non.size() - i];
        }
        else
        {
            ans[l++] = non[(int)non.size() - i];
        }
    }
    assert(l > r);
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }
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
