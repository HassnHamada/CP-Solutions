#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
typedef long long int ll;
// #include <chrono>
// using namespace std::chrono;

const int N = 20;
ll arr[N], n, k;

ll asd(int b)
{
    ll ret = n, bc = 0;
    for (int i = 0; i < k; i++)
    {
        if (b & (1 << i))
        {
            ret /= arr[i];
            bc++;
            // ret *= arr[i];
        }
    }
    return ret * (bc & 1 ? 1 : -1);
}
void run()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    ll ans = 0;
    for (int i = 1; i < (1 << k); i++)
    {
        ans += asd(i);
        // cout << ans << endl;
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
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