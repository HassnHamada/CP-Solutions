#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e3 + 10;
int grid[N][N], n, m;

bool ok(int i, int j, int d)
{
    return 0 <= i && i < n && 0 <= j && j < m && (grid[i][j] & (1 << d)) == 0 and (grid[i][j] & (1 << 4)) == 0;
}

int dfs(int i, int j, int d)
{
    if (!ok(i, j, d))
    {
        return 0;
    }
    grid[i][j] |= 1 << 4;
    return 1 + dfs(i, j - 1, 2) + dfs(i + 1, j, 3) + dfs(i, j + 1, 0) + dfs(i - 1, j, 1);
}

void run()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] & (1 << 4))
            {
                continue;
            }
            ans.push_back(dfs(i, j, 4));
        }
    }

    sort(ans.begin(), ans.end(), greater<int>());
    for (auto &&i : ans)
    {
        cout << i << " ";
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