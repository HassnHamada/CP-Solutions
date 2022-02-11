#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 1e5 + 10;
int vis[N], head[N], nxt[N << 1], to[N << 1], cst[N << 1], ei, vid;

void addEdge(int u, int v, int c)
{
    nxt[ei] = head[u];
    to[ei] = v;
    cst[ei] = c;
    head[u] = ei++;
}

void addBiEdge(int u, int v, int c)
{
    addEdge(u, v, c);
    addEdge(v, u, c);
}

void bfs(int n, int d, vector<int> &ret)
{
    queue<int> q;
    q.push(n);
    vis[n] = vid;
    int cd = 0;
    while (!q.empty())
    {
        cd += 1;
        queue<int> nq;
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            for (int i = head[c]; ~i; i = nxt[i])
            {
                ret.push_back(cst[i]);
                if (vis[to[i]] == vid)
                {
                    continue;
                }
                nq.push(to[i]);
                vis[to[i]] = vid;
            }
        }
        if (cd == d)
        {
            break;
        }
        swap(q, nq);
    }
}

void run()
{
    int n, m, u, l, k;
    cin >> n >> m >> u >> l >> k;
    memset(head, -1, (n + 1) * sizeof(head[0]));
    ei = 0;
    for (int i = 1, a, b, c; i <= m; i++)
    {
        cin >> a >> b >> c;
        addBiEdge(a, b, c);
    }
    vector<int> vec;
    bfs(u, k, vec);
    // cout << vec.size() << endl;
    assert(vec.size());
    cout << *max_element(vec.begin(), vec.end()) << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen("path.in", "r", stdin);
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    // while (t--)
    while (vid++ < t)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
