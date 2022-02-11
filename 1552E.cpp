#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;
const int N = 110;
int n, k, m, colOrd[N][N];
vector<int> col[N];

struct BIT
{
    int frq[N * N];
    void add(int i, int v)
    {
        for (i++; i <= N * N; i += i & -i)
        {
            frq[i - 1] += v;
        }
    }
    int get(int i)
    {
        int ret = 0;
        for (i++; i; i -= i & -i)
        {
            ret += frq[i - 1];
        }
        return ret;
    }
} str, fin;

bool dfs(int c, vector<pair<int, int>> &ans)
{
    if (c == n)
    {
        return true;
    }
    for (int j = 0; j < k - 1; j++)
    {
        int i = colOrd[c][j];
        // cout << c << " " << i << endl;
        str.add(col[c][i], 1);
        fin.add(col[c][i + 1], 1);
        ans.push_back({col[c][i], col[c][i + 1]});
        if (str.get(col[c][i + 1]) - fin.get(col[c][i] - 1) <= m && dfs(c + 1, ans))
        {
            return true;
        }
        ans.pop_back();
        str.add(col[c][i], -1);
        fin.add(col[c][i + 1], -1);
    }
    return false;
}

void run()
{
    cin >> n >> k;
    m = (n + k - 2) / (k - 1);
    for (int i = 0, v; i < n * k; i++)
    {
        cin >> v;
        col[--v].push_back(i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        iota((int *)(colOrd[i]), (int *)(colOrd[i]) + k - 1, 0);
        sort((int *)(colOrd[i]), (int *)(colOrd[i]) + k - 1, [&i](int j, int l)
             { return col[i][j] - col[i][j + 1] > col[i][l] - col[i][l + 1]; });
        // for (int j = 0; j < k - 1; j++)
        // {
        //     cout << colOrd[i][j] << " ";
        // }
        // cout << endl;
    }
    vector<pair<int, int>> ans;
    dfs(0, ans);
    assert(ans.size() == n);
    for (auto &&i : ans)
    {
        cout << i.first << " " << i.second << endl;
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
