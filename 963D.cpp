#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char str[N], tem[N];
struct Node
{
    const int p;
    const char pch;
    int nxt[M], go[M], link = -1;
    // bool leaf = false;
    int leaf = -1;
    Node(int p = 0, char pch = '$') : p(p), pch(pch)
    {
        memset(nxt, -1, sizeof(nxt));
        memset(go, -1, sizeof(go));
    }
};

vector<Node> tri;
bitset<N> bs;
int ids[N], nid;

int insert(char *ptr)
{
    int v = 0;
    for (int i = 0; *(ptr + i); i++)
    {
        int c = *(ptr + i);
        if (tri[v].nxt[c] == -1)
        {
            tri[v].nxt[c] = tri.size();
            tri.emplace_back(v, c);
        }
        v = tri[v].nxt[c];
    }
    // tri[v].leaf = true;
    return tri[v].leaf == -1 ? tri[v].leaf = nid++ : tri[v].leaf;
}

int go(int, int);

int get_link(int v)
{
    if (tri[v].link == -1)
    {
        if (v == 0 || tri[v].p == 0)
        {
            tri[v].link = 0;
        }
        else
        {
            tri[v].link = go(get_link(tri[v].p), tri[v].pch);
        }
    }
    return tri[v].link;
}

int go(int v, int c)
{
    if (tri[v].go[c] == -1)
    {
        if (tri[v].nxt[c] == -1)
        {
            tri[v].go[c] = v ? go(get_link(v), c) : 0;
        }
        else
        {
            tri[v].go[c] = tri[v].nxt[c];
        }
    }
    return tri[v].go[c];
}

void match(char *ptr)
{
    int v = 0;
    for (int i = 0; *(ptr + i); i++)
    {
        int c = *(ptr + i);
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
            bs[tri[v].leaf] = 1;
        }
    }
}

void run()
{
    tri.emplace_back();
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%s", tem);
        ids[i] = insert(tem);
    }
    scanf("%s", str);
    match(str);
    for (int i = 0; i < q; i++)
    {
        printf(bs[ids[i]] ? "y\n" : "n\n");
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}