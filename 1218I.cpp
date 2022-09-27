#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 8e3 + 10, M = 2e3 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<int> grf[N];
int ids[N], low[N], cyc[N], id, cid;
bool onStk[N];
stack<int> stk;

void dfs(int c)
{
    low[c] = ids[c] = id++;
    onStk[c] = true;
    stk.push(c);
    for (auto &&i : grf[c])
    {
        if (ids[i] == -1)
        {
            dfs(i);
        }
        if (onStk[i])
        {
            low[c] = min(low[c], low[i]);
        }
    }
    if (low[c] == ids[c])
    {
        cyc[c] = cid++;
        while (true)
        {
            int t = stk.top();
            stk.pop();
            onStk[t] = false;
            cyc[t] = cyc[c];
            low[t] = low[c];
            if (t == c)
            {
                break;
            }
        }
    }
}

bool ok(int n)
{
    memset(ids, -1, sizeof(ids[0]) * n << 1);
    for (int i = 0; i < (n << 1); i++)
    {
        if (ids[i] == -1)
        {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cyc[i << 1] == cyc[(i << 1) + 1])
        {
            return false;
        }
    }
    return true;
}

char mat_1[M][M], mat_2[M][M], mjk[M];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(mat_1 + i));
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(mat_2 + i));
    }
    scanf("%s", mjk);
    bool _ok = true;
    for (int i = 0; _ok && i < n; i++)
    {
        for (int j = 0; _ok && j < n; j++)
        {
            int a0 = i << 1, a1 = a0 + 1, b0 = (j + n) << 1, b1 = b0 + 1;
            if (mat_1[i][j] == mat_2[i][j])
            {
                if (mjk[i] == '1' && mjk[j] == '1')
                {
                    grf[a1].push_back(b1);
                    grf[b0].push_back(a0);
                    grf[a0].push_back(b0);
                    grf[b1].push_back(a1);
                }
                else if (mjk[i] == '1' || mjk[j] == '1')
                {
                    if (mjk[i] == '1')
                    {
                        grf[b1].push_back(b0);
                    }
                    else
                    {
                        grf[a1].push_back(a0);
                    }
                }
            }
            else
            {
                if (mjk[i] == '1' && mjk[j] == '1')
                {
                    grf[a0].push_back(b1);
                    grf[b0].push_back(a1);
                    grf[a1].push_back(b0);
                    grf[b1].push_back(a0);
                }
                else if (mjk[i] == '1' || mjk[j] == '1')
                {
                    if (mjk[i] == '1')
                    {
                        grf[b0].push_back(b1);
                    }
                    else
                    {
                        grf[a0].push_back(a1);
                    }
                }
                else
                {
                    _ok = false;
                }
            }
        }
    }
    if (_ok && ok(2 * n))
    {
        // for (int i = 0; i < 2 * n; i++)
        // {
        //     cout << cyc[(i << 1) + 1] << " " << cyc[i << 1] << endl;
        // }
        vector<int> ans;
        for (int i = 0; i < 2 * n; i++)
        {
            if (cyc[(i << 1) + 1] < cyc[i << 1])
            {
                ans.push_back(i);
            }
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0, j = ans.size(); i < j; i++)
        {
            printf((ans[i] / n ? "col %d\n" : "row %d\n"), ans[i] % n);
        }
    }
    else
    {
        printf("-1\n");
    }
    // assert(all_of(ids, ids + N, [](int i)
    //               { return i != -1; }));
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}