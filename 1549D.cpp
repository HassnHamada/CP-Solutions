#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e5 + 10;
// set<int> grf[N];
// bool rem[N];
map<ll, int> mmm, nnn;

void fact(ll v)
{
    // ll i = 2;
    // bool p = true;
    for (ll i = 2; i * i <= v; i++)
    {
        if (v % i == 0)
        {
            nnn[i] = mmm[i] + 1;
            // mmm[i] += 1;
            while (v % i == 0)
            {
                v /= i;
            }
            // p = false;
        }
    }
    if (v != 1)
    {
        mmm[v] += 1;
    }
}

void run()
{
    int n;
    mmm.clear();
    cin >> n;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        fact(v);
        swap(mmm, nnn);
        nnn.clear();
        // for (auto &&j : mmm)
        // {
        //     cout << j.first << " " << j.second << endl;
        // }
        // cout << endl;
    }
    int ans = 0;
    for (auto &&i : mmm)
    {
        ans = max(ans, i.second);
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
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
