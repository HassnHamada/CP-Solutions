#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
// vector<int> aaa[N], bbb[N], grf[N];
// map<pair<int, int>, int> mmm;
// pair<int, int> immm[N];
vector<int> aaa[N], bbb[N];
map<pair<int, int>, vector<pair<int, int>>> grf;
// bitset<N> vis;
map<pair<int, int>, int> cst;
set<pair<int, int>> inq, inqf;

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, u, v; i < k; i++)
    {
        scanf("%d%d", &u, &v);
        // mmm.insert({{u, v}, i});
        // immm[i] = {u, v};
        for (int j = -2; j < 3; j++)
        {
            if (u + j >= 1 && u + j <= n)
            {
                for (auto &&l : aaa[u + j])
                {
                    if (abs(l - v) + abs(j) <= 1)
                    {
                        continue;
                    }
                    // grf[i].push_back(mmm[{u + j, l}]);
                    grf[{u, v}].push_back({u + j, l});
                    grf[{u + j, l}].push_back({u, v});
                }
            }
            if (v + j >= 1 && v + j <= m)
            {
                for (auto &&l : bbb[v + j])
                {
                    if (abs(l - u) + abs(j) <= 1)
                    {
                        continue;
                    }
                    grf[{u, v}].push_back({l, v + j});
                    grf[{l, v + j}].push_back({u, v});
                }
            }
        }
        aaa[u].push_back(v);
        bbb[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        aaa[i].clear();
        aaa[i].shrink_to_fit();
    }
    for (int i = 1; i <= m; i++)
    {
        bbb[i].clear();
        bbb[i].shrink_to_fit();
    }

    // bool addOne = false;
    // if (mmm.find({n, m}) == mmm.end())
    // {
    //     mmm.insert({{n, m}, k});
    //     immm.insert({k, {n, m}});
    //     aaa[n].push_back(m);
    //     bbb[m].push_back(n);
    //     addOne = true;
    // }
    // for (int i = 0; i < k; i++)
    // {
    //     auto it = immm[i];
    //     for (int j = -2; j < 3; j++)
    //     {
    //         if (it.first + j >= 1)
    //         {
    //             for (auto &&l : aaa[it.first + j])
    //             {
    //                 if (abs(l - it.second) + abs(j) <= 1)
    //                 {
    //                     continue;
    //                 }
    //                 grf[i].push_back(mmm[{it.first + j, l}]);
    //             }
    //         }
    //         if (it.second + j >= 1)
    //         {
    //             for (auto &&l : bbb[it.second + j])
    //             {
    //                 if (abs(l - it.first) + abs(j) <= 1)
    //                 {
    //                     continue;
    //                 }
    //                 grf[i].push_back(mmm[{l, it.second + j}]);
    //             }
    //         }
    //     }
    // }
    // for (int i = 0; i < k; i++)
    // {
    //     cout << immm[i].first << " " << immm[i].second << endl;
    //     for (auto &&j : grf[i])
    //     {
    //         cout << immm[j].first << " " << immm[j].second << endl;
    //     }
    //     cout << endl;
    // }
    // memset(cst, -1, sizeof(cst));
    deque<pair<pair<int, int>, int>> q;
    q.push_back({{1, 1}, 0});
    inq.insert({1, 1});
    while (q.size())
    {
        // cout << q.size() << endl;
        auto f = q.front();
        q.pop_front();
        auto x = f.first;
        auto y = f.second;
        if (cst.find(x) != cst.end())
        {
            continue;
        }
        // vis[x].flip();
        cst[x] = y;
        // auto it = immm.find(x);
        // auto it = immm[x];
        // pair<int, int> z = {x.first - 1, x.second};
        vector<pair<int, int>> vec;
        vec.push_back({x.first - 1, x.second});
        vec.push_back({x.first + 1, x.second});
        vec.push_back({x.first, x.second - 1});
        vec.push_back({x.first, x.second + 1});
        for (auto &&z : vec)
        {
            if (grf.find(z) != grf.end())
            {
                if (inqf.find(z) == inqf.end())
                {
                    q.push_front({z, y});
                    inq.insert(z);
                    inqf.insert(z);
                }
            }
        }

        // z = {x.first + 1, x.second};
        // if (grf.find({x.first + 1, x.second}) != grf.end())
        // {
        //     if (cst.find({x.first + 1, x.second}) == cst.end())
        //     {
        //         q.push_front({{x.first + 1, x.second}, y});
        //     }
        // }
        // if (grf.find({x.first, x.second + 1}) != grf.end())
        // {
        //     if (cst.find({x.first, x.second + 1}) == cst.end())
        //     {
        //         q.push_front({{x.first, x.second + 1}, y});
        //     }
        // }
        // if (grf.find({x.first, x.second - 1}) != grf.end())
        // {
        //     if (cst.find({x.first, x.second - 1}) == cst.end())
        //     {
        //         q.push_front({{x.first, x.second - 1}, y});
        //     }
        // }
        for (auto &&i : grf[x])
        {
            if (inq.find(i) == inq.end())
            {
                q.push_back({i, y + 1});
                inq.insert(i);
            }
        }
    }
    // vector<int> vec{n, n - 1, m, m - 1};
    int ans = INF;
    for (auto &&i : cst)
    {
        // cout << i.first.first << " " << i.first.second << " " << i.second << endl;
        if (i.first.first == n || i.first.first == n - 1 || i.first.second == m || i.first.second == m - 1)
        {
            ans = min(ans, i.second);
        }
    }

    // for (int i = 0; i < 4; i++)
    // {
    //     for (auto &&j : (i < 2 ? aaa : bbb)[vec[i]])
    //     {
    //         int c = cst[i < 2 ? mmm[{vec[i], j}] : mmm[{j, vec[i]}]];
    //         if (c == -1)
    //         {
    //             continue;
    //         }
    //         ans = min(ans, c);
    //     }
    // }
    if (grf.find({n, m}) == grf.end())
    {
        printf("%d\n", ans == INF ? -1 : ans + 1);
    }
    else
    {
        printf("%d\n", cst.find({n, m}) == cst.end() ? -1 : cst[{n, m}]);
    }
    // for (int i = 0; i < k; i++)
    // {
    //     cout << immm[i].first << " " << immm[i].second << " " << cst[i] << endl;
    // }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}