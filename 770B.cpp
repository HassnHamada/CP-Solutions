#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

ll sz(ll n)
{
    ll r = 0;
    while (n)
    {
        r += n % 10;
        n /= 10;
    }
    return r;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string x, y;
    cin >> x;
    if (x.size() == 1)
    {
        cout << x << endl;
        return 0;
    }
    pair<string, int> ans = {x, sz(stoll(x))};
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '0')
        {
            y.push_back('0');
            continue;
        }
        if (x[i] > '1' || !y.empty())
        {
            y.push_back(x[i] - 1);
        }
        string yy = y + string(x.size() - i - 1, '9');
        cout << yy << endl;
        if (sz(stoll(yy)) == ans.second ? stoll(ans.first) < stoll(yy) : ans.second < sz(stoll(yy)))
        {
            ans = {yy, sz(stoll(yy))};
        }
        if (x[i] > '1' || !y.empty())
        {
            y.pop_back();
        }
        y.push_back(x[i]);
    }
    cout << ans.first << endl;
    // cout << sz(to_string(x), 0, true) << endl;
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
