#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

void run()
{
    ll n, ans = 0, pre = 0;
    cin >> n;
    stack<pair<int, int>> stk;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        int sz = 1;
        while (stk.size() && stk.top().first <= v)
        {
            sz += stk.top().second;
            pre -= 1ll * stk.top().first * stk.top().second;
            stk.pop();
        }
        stk.push({v, sz});
        pre += 1ll * stk.top().first * stk.top().second;
        ans += pre;
    }
    cout << 1.0 * ans / (n * (n + 1) / 2);
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
