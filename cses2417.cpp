#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> prime;
bool is_composite[M];

void linear_sieve(int n = M)
{
    std::fill(is_composite, is_composite + n, false);
    for (int i = 2; i < n; ++i)
    {
        if (!is_composite[i])
            prime.push_back(i);
        for (int j = 0; j < (int)prime.size() && i * prime[j] < n; ++j)
        {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

ll nC2(ll n)
{
    return n * (n - 1) / 2;
}

int arr[N], frq[M], cnt[M];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        frq[arr[i]] += 1;
    }
    linear_sieve();
    ll ans = nC2(n);
    for (int i = 2; i < M; i++)
    {
        // if (is_composite[i])
        // {
        //     continue;
        // }
        // int cnt = 0;
        for (int j = i; j < M; j += i)
        {
            cnt[i] += frq[j];
        }
        // ans -= nC2(cnt);
    }
    set<int> nums;
        for (int i = 0; i * i <= n; i++)
        {
            /* code */
        }

    printf("%lld\n", ans);
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