#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e5 + 10;
ll pre[N], suf[N];

void run()
{
    int n;
    cin >> n;
    vector<ll> mx(3, INT64_MIN);
    for (int i = 1; i <= n; i++)
    {
        cin >> pre[i];
        mx[0] = pre[i];
        sort(mx.begin(), mx.end());
        pre[i] += pre[i - 1];
    }
    for (int i = n; i; i--)
    {
        suf[i] = pre[n] - pre[i - 1];
    }
    ll ans = pre[n] - mx[1] - mx[2];
    for (int i = 1; i <= n - 1; i++)
    {
        ans = min(ans, max(pre[i - 1], i + 2 <= n ? suf[i + 2] : 0));
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen("help.in", "r", stdin);
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}