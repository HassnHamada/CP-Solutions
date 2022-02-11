#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

int cat(string n, string p)
{
    int i = 0, j = 0, ret = 0;
    for (; i < p.size(); i++, j++)
    {
        while (j < n.size() && p[i] != n[j])
        {
            j += 1;
            ret += 1;
        }
        if (j == n.size())
        {
            break;
        }
    }
    assert(p.size() == i || n.size() == j);
    return ret + p.size() - i + n.size() - j;
}

void run()
{
    int n, ans = INT32_MAX;
    cin >> n;
    for (int i = 0; i < 60; i++)
    {
        ans = min(ans, cat(to_string(n), to_string(1ll << i)));
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