#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll l, r, m;
        cin >> l >> r >> m;
        ll mx = r - l, mn = min(m - 1, r - l);
        ll a = (m - mn) / l;
        ll bmc = m - l * a;
        // cout << mx << " " << bmc << endl;
        ll b = r;
        ll c = b - bmc;
        cout << a << " " << b << " " << c << endl;
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
