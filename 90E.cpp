#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char brd[N][N];

struct DT
{
    bool don, del;
    pair<int, int> u, d, l, r;
    DT()
    {
        this->don = this->del = false;
        this->u = this->d = this->l = this->r = {-1, -1};
    }
    void print()
    {
        cout << (this->u.first) << "\t" << (this->u.second) << "\n"
             << (this->d.first) << "\t" << (this->d.second) << "\n"
             << (this->l.first) << "\t" << (this->l.second) << "\n"
             << (this->r.first) << "\t" << (this->r.second) << "\n"
             << "-----------------------------------------------\n";
    }
    pair<int, int> get(char c)
    {
        switch (c)
        {
        case 'U':
            return this->u;
        case 'D':
            return this->d;
        case 'R':
            return this->r;
        case 'L':
            return this->l;
        }
        assert(false);
        return {-1, -1};
    }
};

vector<vector<DT>> grf;

void swap_1(int x, int y)
{
    if (~grf[x][y].u.first && ~grf[x][y].u.second)
    {
        assert(grf[x][y].u.first != -1 && grf[x][y].u.second != -1);
        assert(grf[grf[x][y].u.first][grf[x][y].u.second].d == make_pair(x, y));
        grf[grf[x][y].u.first][grf[x][y].u.second].d = grf[x][y].d;
    }
    if (~grf[x][y].d.first && ~grf[x][y].d.second)
    {
        assert(grf[x][y].d.first != -1 && grf[x][y].d.second != -1);
        assert(grf[grf[x][y].d.first][grf[x][y].d.second].u == make_pair(x, y));
        grf[grf[x][y].d.first][grf[x][y].d.second].u = grf[x][y].u;
    }
    if (~grf[x][y].r.first && ~grf[x][y].r.second)
    {
        assert(grf[x][y].r.first != -1 && grf[x][y].r.second != -1);
        assert(grf[grf[x][y].r.first][grf[x][y].r.second].l == make_pair(x, y));
        grf[grf[x][y].r.first][grf[x][y].r.second].l = grf[x][y].l;
    }
    if (~grf[x][y].l.first && ~grf[x][y].l.second)
    {
        assert(grf[x][y].l.first != -1 && grf[x][y].l.second != -1);
        assert(grf[grf[x][y].l.first][grf[x][y].l.second].r == make_pair(x, y));
        grf[grf[x][y].l.first][grf[x][y].l.second].r = grf[x][y].r;
    }
    grf[x][y].del = !grf[x][y].del;
}

void swap_2(int x, int y)
{
    if (~grf[x][y].u.first && ~grf[x][y].u.second)
    {
        assert(grf[x][y].u.first != -1 && grf[x][y].u.second != -1);
        assert(grf[grf[x][y].u.first][grf[x][y].u.second].d == grf[x][y].d);
        grf[grf[x][y].u.first][grf[x][y].u.second].d = make_pair(x, y);
    }
    if (~grf[x][y].d.first && ~grf[x][y].d.second)
    {
        assert(grf[x][y].d.first != -1 && grf[x][y].d.second != -1);
        assert(grf[grf[x][y].d.first][grf[x][y].d.second].u == grf[x][y].u);
        grf[grf[x][y].d.first][grf[x][y].d.second].u = make_pair(x, y);
    }
    if (~grf[x][y].r.first && ~grf[x][y].r.second)
    {
        assert(grf[x][y].r.first != -1 && grf[x][y].r.second != -1);
        assert(grf[grf[x][y].r.first][grf[x][y].r.second].l == grf[x][y].l);
        grf[grf[x][y].r.first][grf[x][y].r.second].l = make_pair(x, y);
    }
    if (~grf[x][y].l.first && ~grf[x][y].l.second)
    {
        assert(grf[x][y].l.first != -1 && grf[x][y].l.second != -1);
        assert(grf[grf[x][y].l.first][grf[x][y].l.second].r == grf[x][y].r);
        grf[grf[x][y].l.first][grf[x][y].l.second].r = make_pair(x, y);
    }
    grf[x][y].del = !grf[x][y].del;
}

void calc_grf(int x, int y, int n, int m)
{
    if (grf[x][y].don)
    {
        return;
    }
    grf[x][y].don = true;
    for (int i = x + 1; i < n; i++)
    {
        if (brd[i][y] == '.')
        {
            continue;
        }
        grf[x][y].d = {i, y};
        grf[i][y].u = {x, y};
        calc_grf(i, y, n, m);
        break;
    }
    for (int i = y + 1; i < m; i++)
    {
        if (brd[x][i] == '.')
        {
            continue;
        }
        grf[x][y].r = {x, i};
        grf[x][i].l = {x, y};
        calc_grf(x, i, n, m);
        break;
    }
}

map<int, int, greater<int>> ans;


int solve(int x, int y)
{
    // cout << "in " << x << " " << y << endl;
    assert(brd[x][y] != '.');
    assert(!grf[x][y].del);
    auto [a, b] = grf[x][y].get(brd[x][y]);
    if (a == -1 || b == -1)
    {
        assert(a == -1 && b == -1);
        // cout << "out 1" << endl;
        return 1;
    }
    swap_1(x, y);
    int ret = solve(a, b) + 1;
    swap_2(x, y);
    // cout << "out " << ret << endl;
    return ret;
}

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    grf = vector<vector<DT>>(n, vector<DT>(m));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(brd + i));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (brd[i][j] == '.' || grf[i][j].don)
            {
                continue;
            }
            calc_grf(i, j, n, m);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (brd[i][j] == '.')
            {
                continue;
            }
            ans[solve(i, j)]++;
        }
    }
    printf("%d %d\n", ans.begin()->first, ans.begin()->second);
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
