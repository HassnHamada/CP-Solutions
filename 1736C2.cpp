#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 10, M = 3e5, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N], ans[N], sz[N];
ll qans[N];

struct QQQ
{
    int p, x, i;
    bool operator<(const QQQ &other) const
    {
        if (p == other.p)
        {
            return x < other.x;
        }
        return p < other.p;
    }
} qqq[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        arr[i] -= i;
        ans[i] = n + 1;
    }
    set<int> q;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && arr[i] <= -(*q.begin()))
        {
            ans[*q.begin()] = i;
            q.erase(q.begin());
        }
        sz[i] = q.size();
        q.insert(i);
    }
    ll _ans = 0;
    for (int i = 1; i <= n; i++)
    {
        _ans += ans[i] - i;
    }
    // cout << _ans << endl;
    int _q;
    scanf("%d", &_q);
    for (int i = 0; i < _q; i++)
    {
        scanf("%d%d", &qqq[i].p, &qqq[i].x);
    }
    sort(qqq, qqq + _q);
    q.clear();
    for (int i = 1, j = 0; i <= n && j < _q; i++)
    {
        ll tem = _ans;
        if (qqq[j].p == i)
        {
            arr[i] = qqq[j].x - i;
        }
        while (!q.empty() && arr[i] <= -(*q.begin()))
        {
            tem = tem - ans[*q.begin()] + i;
            q.erase(q.begin());
        }
        if (qqq[j].p == i)
        {
            qans[qqq[j++].i] = tem;
            i--;
            continue;
        }
        q.insert(i);
    }
    for (int i = 0; i < _q; i++)
    {
        printf("%lld\n", qans[i]);
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