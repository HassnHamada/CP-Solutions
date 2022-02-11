#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

void run()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        ans = i ? ans & v : v;
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
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