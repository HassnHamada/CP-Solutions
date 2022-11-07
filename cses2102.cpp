#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10, M = 26, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

struct Node
{
    int p, pch, link = -1, leaf = -1;
    int nxt[M], go[M];
    Node(int _p = -1, int _pch = -1)
    {
        p = _p;
        pch = _pch;
        memset(nxt, -1, sizeof(nxt));
        memset(go, -1, sizeof(go));
    }
};

vector<Node> tri;
int id[N], nid;

int add(char *str)
{
    int v = 0;
    for (int i = 0; *(str + i); i++)
    {
        int c = (*(str + i)) - 'a';
        if (tri[v].nxt[c] == -1)
        {
            tri[v].nxt[c] = tri.size();
            tri.emplace_back(v, c);
        }
        v = tri[v].nxt[c];
    }
    return tri[v].leaf == -1 ? tri[v].leaf = nid++ : tri[v].leaf;
}

bitset<N> ans;

int go(int, int);

int get_link(int n)
{
    assert(n >= 0);
    if (tri[n].link == -1)
    {
        if (n == 0 || tri[n].p == 0)
        {
            tri[n].link = 0;
        }
        else
        {
            tri[n].link = go(get_link(tri[n].p), tri[n].pch);
        }
    }
    if (tri[n].leaf != -1)
    {
        ans[tri[n].leaf] = 1;
    }
    return tri[n].link;
}

int go(int n, int c)
{
    assert(n >= 0);
    if (tri[n].go[c] == -1)
    {
        if (tri[n].nxt[c] == -1)
        {
            tri[n].go[c] = n ? go(get_link(n), c) : 0;
        }
        else
        {
            tri[n].go[c] = tri[n].nxt[c];
        }
    }
    if (tri[n].leaf != -1)
    {
        ans[tri[n].leaf] = 1;
    }
    return tri[n].go[c];
}

void match(char *str)
{
    int v = 0;
    for (int i = 0; *(str + i); i++)
    {
        int c = (*(str + i)) - 'a';
        while (v && tri[v].nxt[c] == -1)
        {
            v = get_link(v);
        }
        if (tri[v].nxt[c] != -1)
        {
            v = tri[v].nxt[c];
        }
        if (tri[v].leaf != -1)
        {
            ans[tri[v].leaf] = 1;
        }
    }
    while ((v = get_link(v)))
    {
        if (tri[v].leaf != -1)
        {
            ans[tri[v].leaf] = 1;
        }
    }
}
char pat[N], buf[N];

void run()
{
    int k;
    scanf("%s%d", pat, &k);
    tri.emplace_back();
    for (int i = 0; i < k; i++)
    {
        scanf("%s", buf);
        id[i] = add(buf);
    }
    ans.reset();
    match(pat);
    for (int i = 0; i < k; i++)
    {
        printf(ans[id[i]] ? "YES\n" : "NO\n");
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}