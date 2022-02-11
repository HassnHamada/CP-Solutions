#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

void run()
{
    ll n, m, k;
    cin >> n >> m >> k;
    if (m > n * (n - 1) / 2 || m < n - 1)
    {
        cout << "NO\n";
    }
    else
    {
        if (n > 1)
        {
            int c = (m == n * (n - 1) / 2 ? 1 : 2);
            cout << (c < k - 1 ? "YES\n" : "NO\n");
        }
        else
        {
            cout << (k > 1 ? "YES\n" : "NO\n");
        }
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
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
