#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct Node
{
    ll i, a, b;
    Node(ll ni, ll na, ll nb)
    {
        this->i = ni;
        this->a = na;
        this->b = nb;
    }
};
vector<Node> arr[N];

int ans[N];

void dfs(int n, int p, ll c, vector<ll> &vec)
{
    ans[n] = upper_bound(vec.begin(), vec.end(), c) - vec.begin() - 1;
    for (auto &&i : arr[n])
    {
        if (i.i == p)
        {
            continue;
        }
        vec.push_back(vec.back() + i.b);
        dfs(i.i, n, c + i.a, vec);
        vec.pop_back();
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int p, a, b;
        scanf("%d%d%d", &p, &a, &b);
        arr[p].emplace_back(i, a, b);
    }
    vector<ll> vec;
    vec.push_back(0);
    dfs(1, 0, 0, vec);
    for (int i = 2; i <= n; i++)
    {
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i].clear();
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
