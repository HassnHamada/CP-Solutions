#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const long long MOD = 1e9 + 7, OO = 1e18;
const double PI = acos(-1);
const int N = 1e3 + 5, M = 15;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

typedef long long ll;

long long n, k, dp[N][N][M], a[N];
vector<long long> ans;
// set<pair<ll, ll>> vis[N][N];
set<pair<ll, ll>> vis;

// bool magic(int i, int j, set<int> &s)
bool magic(set<int> &s)
{
    // if (i > j)
    // {
    //     i = j = n + 1;
    // }
    assert((int)(s.size()) <= 10);
    if (!s.empty())
    {
        pair<ll, ll> key{0, 0};
        auto it = s.begin();
        for (int ii = 0; ii < 5 && it != s.end(); ii++)
        {
            key.first <<= 10;
            key.first |= *it;
            it++;
        }
        for (int ii = 0; it != s.end(); ii++)
        {
            assert(ii < 5);
            key.second <<= 10;
            key.second |= *it;
            it++;
        }
        // if (vis[i][j].find(key) != vis[i][j].end())
        if (vis.find(key) != vis.end())
        {
            return false;
        }
        vis.insert(key);
    }
    return true;
}

long long solve(long long i, long long j, long long cnt, set<int> &s)
{
    if (cnt < 0)
    {
        return 0;
    }
    if (i > j)
    {
        if (!magic(s))
        // if (!magic(i, j, s))
        {
            return 0;
        }
        cout << i << " ------- " << j << endl;
        for (auto &&iii : s)
        {
            cout << iii << " ";
        }
        cout << endl;
        return cnt == 0;
    }
    long long &ret = dp[i][j][cnt];
    if (~ret)
    {
        // if (!magic(i, j, s))
        // if (!magic(s))
        // {
        //     return 0;
        // }
        return ret;
    }

    long long c1 = 0;
    if (a[i] == a[j])
    {
        c1 = solve(i + 1, j - 1, cnt, s);
    }
    s.insert(i);
    long long c2 = solve(i + 1, j, cnt - 1, s);
    s.erase(i);
    s.insert(j);
    long long c3 = solve(i, j - 1, cnt - 1, s);
    s.erase(j);
    return ret = c1 + c2 + c3;
}

int main()
{
    // IO
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    set<int> s;
    cout << solve(1, n, k, s) << endl;
    return 0;
}