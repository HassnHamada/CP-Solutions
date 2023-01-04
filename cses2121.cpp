#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e2 + 10, M = 1 << 12, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

struct DT
{
    int u, v, r, c;
    DT(int u_, int v_, int r_, int c_)
    {
        u = u_;
        v = v_;
        r = r_;
        c = c_;
    }
};

vector<DT> edg;
set<int> grf[N];
int cst[N], path[N];

void dijkstra(int sz)
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    memset(cst, 0x3f, sizeof(cst[0]) * sz);
    pq.push({cst[1] = 0, 1, -1});
    while (!pq.empty())
    {
        auto [c, n, p] = pq.top();
        // cout << n << " " << c << "\n";
        pq.pop();
        if (cst[n] != c)
        {
            continue;
        }
        // cout << "ok\n";
        path[n] = p;
        if (n == sz - 1)
        {
            break;
        }
        for (auto &&i : grf[n])
        {
            // cout << i << " ";
            // auto [u_, v_, r_, c_] = edg[i];
            // cout << u_ << " " << v_ << " " << r_ << " " << c_ << "\n";
            assert(edg[i].u == n);
            if (edg[i].c + c <= cst[edg[i].v])
            {
                pq.push({cst[edg[i].v] = edg[i].c + c, edg[i].v, i});
            }
        }
        // cout << endl;
    }
}

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, u, v, r, c; i < m; i++)
    {
        scanf("%d%d%d%d", &u, &v, &r, &c);
        if (u == v)
        {
            continue;
        }
        grf[u].insert(edg.size());
        // grf[v].insert(edg.size());
        edg.emplace_back(u, v, r, c);
    }
    int ans = 0;
    while (k)
    {
        // cout << k << endl;
        dijkstra(n + 1);
        // cout << k << endl;
        if (cst[n] == INF)
        {
            ans = -1;
            break;
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << path[i] << " ";
        // }
        // cout << endl;
        int t = k;
        for (int i = n; i > 1;)
        {
            auto [u_, v_, r_, c_] = edg[path[i]];
            cout << u_ << " " << v_ << " " << r_ << " " << c_ << "\n";
            assert(v_ == i);
            assert(grf[u_].find(path[i]) != grf[u_].end());
            assert(r_);
            t = min(t, r_);
            i = u_;
        }
        cout << endl;
        cout << t << " " << cst[n] << endl;
        bool del = false;
        for (int i = n; i > 1;)
        {
            auto [u_, v_, r_, c_] = edg[path[i]];
            assert((edg[path[i]].r -= t) >= 0);
            if (edg[path[i]].r == 0)
            {
                grf[u_].erase(path[i]);
                // grf[v_].erase(path[i]);
                del = true;
            }
            assert(v_ == i);
            // cout << u_ << " " << v_ << " " << edg[path[i]].r << " " << c_ << "\n";
            i = u_;
        }
        k -= t;
        ans += t * cst[n];
        assert(del || k == 0);
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}