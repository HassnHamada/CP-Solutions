#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

void run()
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (a < b)
    {
        swap(a, b);
    }
    if (a < c)
    {
        swap(a, c);
    }
    if (b < c)
    {
        swap(b, c);
    }
    int lm = max(a - b - c - 1, 0), hm = a + b + c - 3;
    cout << (m >= lm && m <= hm ? "YES" : "NO") << endl;
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
