#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
const long long MOD = 1e9 + 7, OO = 1e18;
const double PI = acos(-1);
const int N = 1e5 + 10;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int par[N];

struct Node
{
    int p, d;
    set<int> c;

    Node(int p)
    {
        this->p = p;
        d = 0;
    }
};

vector<Node> tre;

void add(int n)
{
    tre.emplace_back(n);
    tre[n].c.insert(tre.size() - 1);
}

int get(int n)
{
    if (n == -1)
    {
        return -1;
    }
    if (tre[n].d == 0)
    {
        return n;
    }
    for (int i : tre[n].c)
    {
        int v = get(i);
        if (~v)
        {
            return v;
        }
    }
    return -1;
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    tre.emplace_back(-1);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        par[i] = i;
    }
    vector<int> stk;
    stk.push_back(0);
    while (q--)
    {
        int t, x;
        scanf("%d%d", &t, &x);
        if (t == 1)
        {
            add(x - 1);
        }
        else
        {
            x -= 1;
            tre[x].d = 1;
            int ans = -1;
            while (ans == -1)
            {
                int v = stk.back();
                ans = get(v);
                if (~ans)
                {
                    if (v != ans)
                    {
                        stk.push_back(ans);
                    }
                }
                else
                {
                    int p = tre[v].p;
                    if (~p)
                    {
                        tre[p].c.erase(v);
                    }
                    stk.pop_back();
                    assert(stk.size());
                }
            }
            assert(ans != -1);
            printf("%d\n", ans + 1);
        }
    }
    return 0;
}
