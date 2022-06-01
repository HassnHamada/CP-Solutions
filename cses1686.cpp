#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 1e5 + 10, EMP = -1;
int n, m, id, ids[N], low[N], coi[N];
ll coi2[N], dp[N];
bool onStk[N];
vector<int> grf[N], grf2[N];
stack<int> stk;

void dfs(int c)
{
    // cout << "IN " << c << endl;
    low[c] = ids[c] = id++;
    onStk[c] = true;
    stk.push(c);
    for (auto &&i : grf[c])
    {
        if (ids[i] == EMP)
        {
            dfs(i);
        }
        if (onStk[i])
        {
            low[c] = min(low[c], low[i]);
        }
    }
    if (ids[c] == low[c])
    {
        while (!stk.empty())
        {
            int t = stk.top();
            stk.pop();
            onStk[t] = false;
            low[t] = low[c];
            // cout << c << " " << t << " " << low[c] << " " << low[t] << endl;
            if (t == c)
            {
                break;
            }
        }
    }
    // cout << "OUT " << c << endl;
}

void tarjan()
{
    for (int i = 1; i <= n; i++)
    {
        ids[i] = EMP;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ids[i] == EMP)
        {
            dfs(i);
        }
    }
}

void getInp()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> coi[i];
    }
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        grf[a].push_back(b);
    }
}

int comp()
{
    vector<int> tem(low + 1, low + n + 1);
    sort(tem.begin(), tem.end());
    int l = unique(tem.begin(), tem.end()) - tem.begin();
    for (int i = 1; i <= n; i++)
    {
        low[i] = lower_bound(tem.begin(), tem.begin() + l, low[i]) - tem.begin();
    }
    return l;
}

ll calc(int c)
{
    ll &ret = dp[c];
    if (ret)
    {
        return ret;
    }
    ret = coi2[c];
    for (auto &&i : grf2[c])
    {
        ret = max(ret, calc(i) + coi2[c]);
    }
    return ret;
}

void run()
{
    getInp();
    tarjan();
    int t = comp();
    for (int i = 1; i <= n; i++)
    {
        for (auto &&j : grf[i])
        {
            if (low[i] != low[j])
            {
                grf2[low[i]].push_back(low[j]);
            }
        }
        coi2[low[i]] += coi[i];
    }
    ll ans = 0;
    for (int i = 0; i < t; i++)
    {
        ans = max(ans, calc(i));
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    freopen(".\\_input.txt", "r", stdin);
    freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}