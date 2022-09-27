#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 2e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char buf[M << 1];
pair<string, string> inp[N];
string str[N << 1];
vector<int> grf[N];
map<string, int> cnt;

int vis[N], vid = 1;
int nxt_s[N], nxt_t[N << 1];

bool canCon(int ii)
{
    if (vis[ii] == vid)
    {
        return false;
    }
    vis[ii] = vid;
    for (auto &&i : grf[ii])
    {
        if (nxt_t[i] == -1 || canCon(nxt_t[i]))
        {
            nxt_s[ii] = i;
            nxt_t[i] = ii;
            return true;
        }
    }
    return false;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", buf, buf + M);
        str[i << 1] = inp[i].first = string(buf, buf + 3);
        str[(i << 1) + 1] = inp[i].second = string(buf, buf + 2) + string(buf + M, buf + M + 1);
        cnt[inp[i].first]++;
    }
    sort(str, str + (n << 1));
    int m = unique(str, str + (n << 1)) - str;
    for (int i = 0; i < n; i++)
    {
        if (cnt[inp[i].first] == 1)
        {
            grf[i].push_back(lower_bound(str, str + m, inp[i].first) - str);
            assert(grf[i].back() != m);
        }
        grf[i].push_back(lower_bound(str, str + m, inp[i].second) - str);
        assert(grf[i].back() != m);
    }
    memset(nxt_s, -1, sizeof(nxt_s));
    memset(nxt_t, -1, sizeof(nxt_t));
    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (nxt_s[i] == -1)
        {
            for (auto &&j : grf[i])
            {
                if (nxt_t[j] == -1)
                {
                    nxt_s[i] = j;
                    nxt_t[j] = i;
                    break;
                }
            }
        }
    }
    for (int i = 0; ok && i < n; i++, vid++)
    {
        if (nxt_s[i] == -1 && canCon(i))
        {
            // pass
        }
        ok = nxt_s[i] != -1;
    }
    if (ok)
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
        {
            assert(nxt_s[i] < m && nxt_s[i] >= 0);
            printf("%s\n", str[nxt_s[i]].c_str());
        }
    }
    else
    {
        printf("NO\n");
    }
    // for (int i = 0; i < m; i++)
    // {
    //     printf("%s\n", str[i].c_str());
    // }
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