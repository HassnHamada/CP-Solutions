#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 60;
ll pow2[N];

int sz(ll n)
{
    int ret = 0;
    while (n)
    {
        ret++;
        n /= 2;
    }
    return ret;
}

ll ans(ll n)
{
    ll ret = 0;
    for (int i = 1; i <= sz(n); i++)
    {
        ret += n / pow2[i] * pow2[i - 1] + max(n % pow2[i] - pow2[i - 1] + 1, 0ll);
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    pow2[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pow2[i] = 2ll * pow2[i - 1];
    }
    ll n;
    cin >> n;
    cout << ans(n) << endl;

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}