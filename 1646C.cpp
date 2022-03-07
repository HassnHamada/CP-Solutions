#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e12 + 10;
// int arr[N];
map<ll, ll> powerful;

void pre()
{
    vector<ll> vec;
    for (ll i = 2, t = 1; t < N; t *= i++)
    {
        vec.push_back(t);
    }
    int n = vec.size();
    for (int i = 0; i < (1 << n); i++)
    {
        ll v = 0, w = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                v += vec[j];
                w += 1;
            }
        }
        powerful.insert({v, w});
    }
}

void run()
{
    ll n;
    scanf("%lld", &n);
    ll ans = (ll)(1e9);
    for (auto &&i : powerful)
    {
        ans = min(ans, i.second + __builtin_popcountll(n - i.first));
    }
    printf("%lld\n", ans == (ll)(1e9) ? -1ll : ans);
}

int main(int argc, char const *argv[])
{
    // freopen("./_input.txt", "r", stdin);
    // freopen("./_output.txt", "w", stdout);
    pre();
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
