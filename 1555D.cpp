#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
int pre[6][N];

void run()
{
    int n, m;
    string s, p = "abc";
    cin >> n >> m >> s;
    for (int j = 0; j < 6; j++)
    {
        // cout << p << endl;
        for (int i = 0; i < n; i++)
        {
            pre[j][i + 1] = pre[j][i] + (s[i] == p[i % 3] ? 0 : 1);
            // cout << pre[j][i] << " " << pre[j][i + 1] << "\n";
            // cout << pre[j][i + 1] << " ";
        }
        // cout << endl;
        next_permutation(p.begin(), p.end());
    }
    for (int i = 0, l, r; i < m; i++)
    {
        cin >> l >> r;
        int ans = INT32_MAX;
        for (int j = 0; j < 6; j++)
        {
            ans = min(ans, pre[j][r] - pre[j][l - 1]);
        }
        cout << ans << endl;
    }
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
