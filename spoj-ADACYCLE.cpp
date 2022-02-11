#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2010;
int vis[N];
vector<int> grf[N];

int bfs(int n)
{
    queue<int> q;
    q.push(n);
    vis[n] = n;
    int ret = 0;
    while (!q.empty())
    {
        ret += 1;
        queue<int> nq;
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            for (auto &&i : grf[c])
            {
                if (i == n)
                {
                    return ret;
                }
                if (vis[i] == n)
                {
                    continue;
                }
                nq.push(i);
                vis[i] = n;
            }
        }
        swap(q, nq);
    }
    return 0;
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

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1, v; j <= n; j++)
        {
            cin >> v;
            if (v)
            {
                grf[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int ret = bfs(i);
        if (ret)
        {
            cout << ret << endl;
        }
        else
        {
            cout << "NO WAY\n";
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
