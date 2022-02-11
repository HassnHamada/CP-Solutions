#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
set<int> grf[N];
bool rem[N];

int asd(int u)
{
    bool ok = grf[u].lower_bound(u) != grf[u].end();
    return rem[u] ? (ok ? 0 : (rem[u] = false, -1)) : (ok ? rem[u] = ok : 0);
}

void run()
{
    int n, m, ans;
    cin >> n >> m;
    ans = n;
    for (int i = 0, u, v; i < m; i++)
    {
        cin >> u >> v;
        grf[u].insert(v);
        grf[v].insert(u);
        ans -= asd(u);
        ans -= asd(v);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int o, u, v;
        cin >> o;
        if (o == 1)
        {
            cin >> u >> v;
            grf[u].insert(v);
            grf[v].insert(u);
            ans -= asd(u);
            ans -= asd(v);
        }
        else if (o == 2)
        {
            cin >> u >> v;
            grf[u].erase(v);
            grf[v].erase(u);
            ans -= asd(u);
            ans -= asd(v);
        }
        else
        {
            cout << ans << endl;
        }
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
