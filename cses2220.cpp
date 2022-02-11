#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

ll dp[20][10][2][2];

ll work(int n, int m, int s, int c, const string &str)
{
    if (!n)
    {
        return 1;
    }
    if (~dp[n][m][s][c])
    {
        return dp[n][m][s][c];
    }
    ll ret = 0;
    for (int i = 0, j = (c ? str[n - 1] - '0' : 9); i <= j; i++)
    {
        if (i == m && s == 0)
        {
            continue;
        }
        ret += work(n - 1, i, s && (i == 0), c && (i == j), str);
    }
    return dp[n][m][s][c] = ret;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ll a, b;
    cin >> a >> b;
    string aaa = to_string(a - 1), bbb = to_string(b);
    reverse(aaa.begin(), aaa.end());
    reverse(bbb.begin(), bbb.end());
    memset(dp, -1, sizeof(dp));
    a = work(aaa.size(), 0, 1, 1, aaa);
    memset(dp, -1, sizeof(dp));
    b = work(bbb.size(), 0, 1, 1, bbb);
    printf("%lld\n", b - a);
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
