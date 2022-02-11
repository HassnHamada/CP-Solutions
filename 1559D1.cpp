#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e3 + 10;

struct DSU
{
    int per[N];
    void init(int n)
    {
        iota(per, per + n, 0);
    }
    void join(int a, int b)
    {
        per[b = find(b)] = a = find(a);
    }
    int find(int a)
    {
        return a == per[a] ? a : per[a] = find(per[a]);
    }
    bool isCon(int a, int b)
    {
        return find(a) == find(b);
    }
} tree1, tree2;

void run()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    tree1.init(n + 1);
    tree2.init(n + 1);
    for (int i = 0, u, v; i < m1; i++)
    {
        cin >> u >> v;
        tree1.join(u, v);
    }
    for (int i = 0, u, v; i < m2; i++)
    {
        cin >> u >> v;
        tree2.join(u, v);
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (tree1.isCon(i, j) || tree2.isCon(i, j))
            {
                continue;
            }
            tree1.join(i, j);
            tree2.join(i, j);
            ans.push_back({i, j});
        }
    }
    cout << ans.size() << endl;
    for (auto &&i : ans)
    {
        cout << i.first << " " << i.second << endl;
    }
}
int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
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