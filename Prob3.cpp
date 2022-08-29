#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
int vis[N], vid;

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
} tre;

int dfs(int n, int c)
{
    vis[c] = vid;
    int ret = 1;
    for (auto &&i : grf[c])
    {
        if (vis[i] == vid)
        {
            continue;
        }
        tre.join(n, i);
        ret += dfs(n, i);
    }
    return ret;
}

void run()
{
    // Input n, m, d, k -number of students in class, number of frind pairs, maximum diferent in team size, number of teams-
    // next m line each contains 2 numbers u and v -u and v are frinds-

    int n, m, d, k;
    scanf("%d%d%d%d", &n, &m, &d, &k);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        grf[u].push_back(v);
        grf[v].push_back(u);
    }
    set<pair<int, int>, greater<pair<int, int>>> pq;
    int mn = INF, mx = -INF;
    vid += 1;
    tre.init(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == vid)
        {
            continue;
        }
        int v = dfs(i, i);
        // pq.insert({v, {i}});
        pq.insert({v, i});
        mn = min(mn, v);
        mx = max(mx, v);
    }
    // cout << pq.size() << endl;
    if ((int)pq.size() < k)
    {
        printf("-1\n");
    }
    else
    {
        set<pair<int, int>, greater<pair<int, int>>> extra;
        while ((int)pq.size() > k)
        {
            auto a = *pq.rbegin();
            extra.insert(a);
            pq.erase(a);
        }
        while ((int)extra.size() > k)
        {
            auto a = *extra.rbegin();
            extra.erase(a);
            auto b = *extra.rbegin();
            extra.erase(b);
            a.first += b.first;
            tre.join(a.second, b.second);
            extra.insert(a);
        }

        while (!extra.empty())
        {
            // auto a = pq.top();
            // pq.pop();
            // auto b = pq.top();
            // pq.pop();
            auto a = *extra.begin();
            // cout << a.first << endl;
            extra.erase(a);
            // cout << a.first << " " << mx - a.first << endl;
            auto bi = pq.lower_bound({mx - a.first, 0});
            // cout << a.first << " " << b.first << endl;
            auto b = bi == pq.end() ? *pq.rbegin() : *bi;
            pq.erase(b);
            // if (a.second.size() < b.second.size())
            // {
            //     swap(a, b);
            // }
            // cout << a.first << " " << b.first << endl;
            a.first += b.first;
            // for (auto &&i : b.second)
            // {
            //     a.second.push_back(i);
            // }
            tre.join(a.second, b.second);
            mx = max(mx, a.first);
            // pq.push(a);
            // mn = pq.top().first;
            pq.insert(a);
            mn = pq.rbegin()->first;
        }
        // cout << mx << " " << mn << endl;
        if (mx - mn > d)
        {
            printf("-1\n");
        }
        else
        {
            map<int, vector<int>> ans;
            for (int i = 1; i <= n; i++)
            {
                ans[tre.find(i)].push_back(i);
            }
            assert((int)ans.size() == k);
            for (auto &&i : ans)
            {
                for (auto &&j : i.second)
                {
                    printf("%d ", j);
                }
                printf("\n");
            }
        }
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}