#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

std::vector<int> prime;
bool is_composite[N];

void linear_sieve(int n)
{
    std::fill(is_composite, is_composite + n, false);
    for (int i = 2; i < n; ++i)
    {
        if (!is_composite[i])
            prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < n; ++j)
        {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int arr[N], div_[M];

void sieve()
{
    for (ll i = 2; i < M; i++)
    {
        if (div_[i])
        {
            continue;
        }
        div_[i] = i;
        for (ll j = i * i; j < M; j += i)
        {
            div_[j] = i;
        }
    }
}

set<int> get_div(int n)
{
    // set<int> ret = {n};
    set<int> ret;
    while (n != 1)
    {
        // cout << n << " " << div_[n] << endl;
        assert(div_[n]);
        assert(n % div_[n] == 0);
        ret.insert(n);
        ret.insert(div_[n]);
        // ret.insert(n /= div_[n]);
        n /= div_[n];
    }
    return ret;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    sieve();
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        // cout << i << " " << arr[i] << endl;
        if (arr[i] == 1)
        {
            continue;
        }
        int tem = 0;
        for (auto &&j : get_div(arr[i]))
        {
            // cout << "nuin\n";
            // cout << j << " ";
            auto l = lower_bound(arr, arr + i, j),
                 h = upper_bound(arr, arr + i, j);
            tem += h - l;
        }
        // cout << endl;
        assert(i >= tem);
        ans += i - tem;
        cout << i - tem << endl;
    }
    printf("%lld\n", ans);
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}