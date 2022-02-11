#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 4e5 + 10;
int ans[N], ind[N], vis[N], vid;
bool pth[N];
vector<int> grf[N], cyc, two;

void insert(int n, int v)
{
    if (ind[n] == grf[n].size())
    {
        grf[n].resize(2 * max(ind[n], 1));
    }
    grf[n][ind[n]++] = v;
}

void dfs(int n, int v)
{
    if (vis[n] == vid)
    {
        if (v == 1)
        {
            (pth[n] ? cyc : two).push_back(n);
        }
        return;
    }
    ans[n] = v;
    vis[n] = vid;
    pth[n] = true;
    for (int i = 0; i < ind[n]; i++)
    {
        dfs(grf[n][i], v);
    }
    pth[n] = false;
}

void run()
{
    int n, m;
    cin >> n >> m;
    memset(ind, 0, n * sizeof(ind[0]));
    memset(ans, 0, n * sizeof(ans[0]));
    cyc.clear();
    two.clear();
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        insert(--a, --b);
    }
    vid += 1;
    dfs(0, 1);
    vid += 1;
    for (auto &&i : cyc)
    {
        if (vis[i] == vid)
        {
            continue;
        }
        dfs(i, -1);
    }
    for (auto &&i : two)
    {
        if (vis[i] == vid)
        {
            continue;
        }
        dfs(i, 2);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i + 1 == n];
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
    int test;
    cin >> test;
    while (test--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
