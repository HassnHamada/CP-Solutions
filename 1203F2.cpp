#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 100, R = 6e4 + 10;
pair<int, int> pos[N], neg[N];
int dp[N][R];

bool com(const pair<int, int> &p1, const pair<int, int> &p2)
{
    int a = p1.first + p1.second,
        b = p2.first + p2.second;
    if (a == b)
    {
        return p1.first < p2.first;
    }
    return a < b;
}

void run()
{
    int n, r, ps = 0, ns = 0, ans = 0;
    cin >> n >> r;
    for (int i = 0, a, b; i < n; i++)
    {
        cin >> a >> b;
        if (b < 0)
        {
            neg[ns++] = {a, b};
        }
        else
        {
            pos[ps++] = {a, b};
        }
    }
    sort(pos, pos + ps);
    for (int i = 0; i < ps; i++)
    {
        if (pos[i].first <= r)
        {
            r += pos[i].second;
            ans += 1;
        }
    }
    sort(neg, neg + ns, com);
    for (int i = 0; i < ns; i++)
    {
        int m = max(neg[i].first, abs(neg[i].second));
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = i ? dp[i - 1][j] : 0;
        }
        for (int j = m; j < R; j++)
        {
            dp[i][j] = max(i ? dp[i - 1][j] : 0, 1 + (i ? dp[i - 1][j + neg[i].second] : 0));
        }
    }
    cout << ans + (ns ? dp[ns - 1][r] : 0) << endl;
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
