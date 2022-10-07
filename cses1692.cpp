    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    const int N = 1 << 15, M = 15, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
    vector<int> grf[N];
    bool vis[N];
    char buf[N + M];
    char *ans = buf + M;
    int n;

    bool dfs(int c, int p)
    {
        // cout << c << " " << p << endl;
        assert(p < N);
        if (p == (1 << n) - 1)
        {
            return true;
        }
        vis[c] = true;
        for (auto &&i : grf[c])
        {
            if (vis[i])
            {
                continue;
            }
            if (dfs(i, p + 1))
            {
                ans[p] = (i & 1) + '0';
                return true;
            }
        }
        vis[c] = false;
        return false;
    }

    struct DT
    {
        int c, p, i;
    };

    bool dfs_stk(int c, int p)
    {
        stack<DT> stk;
        stk.push({c, p, 0});
        vis[c] = true;
        bool ok = false;
        while (!stk.empty())
        {
            DT &t = stk.top();
            // cout << t.c << " " << t.p << " " << t.i << endl;
            if (t.p == (1 << n) - 1)
            {
                ok = true;
                vis[t.c] = false;
                stk.pop();
                // cout << "c1\n";
                continue;
            }
            if (ok)
            {
                ans[t.p] = (t.i - 1) + '0';
                vis[t.c] = false;
                stk.pop();
                // cout << "c2\n";
                continue;
            }
            while (t.i < (int)grf[t.c].size() && vis[grf[t.c][t.i]])
            {
                t.i++;
            }
            if (t.i == (int)grf[t.c].size())
            {
                vis[t.c] = false;
                stk.pop();
                // cout << "c3\n";
                continue;
            }
            stk.push({grf[t.c][t.i], t.p + 1, 0});
            vis[grf[t.c][t.i++]] = true;
            // cout << "in\n";
        }
        return ok;
    }

    void run()
    {
        scanf("%d", &n);
        for (int i = 0; i < (1 << n); i++)
        {
            int v = (i << 1) & ((1 << n) - 1);
            assert(v + 1 < N);
            grf[i].push_back(v);
            grf[i].push_back(v + 1);
        }
        assert(dfs_stk(0, 0));
        fill(ans - n, ans, '0');
        printf("%s\n", ans - n);
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