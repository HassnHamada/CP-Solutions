#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 26, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int nxtn[N], nxtm[N], ddd1[N], ddd2[N], vis[N], ans[N], vid, n;
vector<int> grf[N];

bool canCon(int ii, int v)
{
    if (vis[ii] == vid)
    {
        return false;
    }
    vis[ii] = vid;
    for (auto &&j : grf[ii])
    {
        if (nxtm[j] == -1 || canCon(nxtm[j], v))
        {
            nxtm[j] = ii;
            nxtn[ii] = j;
            return true;
        }
    }
    return false;
}

bool bpm(int v)
{
    for (int i = 0; i < n; i++)
    {
        grf[i].clear();
        for (int j = 0; j < n; j++)
        {
            if (abs(ddd1[i] - ddd2[j]) == v || ddd1[i] + ddd2[j] == v)
            {
                grf[i].push_back(j);
            }
        }
        if (grf[i].empty())
        {
            return false;
        }
    }
    memset(nxtn, -1, sizeof(nxtn[0]) * n);
    memset(nxtm, -1, sizeof(nxtm[0]) * n);
    for (int i = 0; i < n; i++)
    {
        for (auto &&j : grf[i])
        {
            if (nxtm[j] == -1)
            {
                nxtm[j] = i;
                nxtn[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        vid++;
        if (nxtn[i] == -1 && !canCon(i, v))
        {
            return false;
        }
    }
    return true;
}

int ok()
{
    vector<int> tem;
    for (int i = 0; i < n; i++)
    {
        tem.push_back(abs(ddd1[0] - ddd2[i]));
        tem.push_back(ddd1[0] + ddd2[i]);
    }
    sort(tem.begin(), tem.end());
    tem.erase(unique(tem.begin(), tem.end()), tem.end());
    for (auto &&i : tem)
    {
        if (bpm(i))
        {
            return i;
        }
    }
    return -1;
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ddd1 + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ddd2 + i);
    }
    // sort(ddd1, ddd1 + n);
    // sort(ddd2, ddd2 + n);
    int d = ok();
    if (~d)
    {
        int s = 0;
        printf("YES\n");
        for (int i = 0; i < n; i++)
        {
            if (ddd1[i] + ddd2[nxtn[i]] == d)
            {
                continue;
            }
            s = max(s, ddd1[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (ddd1[i] + ddd2[nxtn[i]] == d)
            {
                ans[i] = s + ddd1[i];
            }
            else
            {
                if (ddd1[i] < ddd2[nxtn[i]])
                {
                    ans[i] = s - ddd1[i];
                }
                else if (ddd1[i] >= ddd2[nxtn[i]])
                {
                    ans[i] = s + ddd1[i];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", ans[i], " \n"[i + 1 == n]);
        }
        printf("%d %d\n", s, s + d);
    }
    else
    {
        printf("NO\n");
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
