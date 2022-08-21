#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 10, M = 2, L = 30, MOD = 1e9 + 9, HV = 151, HV2 = 167, INF = 0x3f3f3f3f;

struct Node
{
    int nxt[M];
    int lev, prv;
    Node()
    {
        memset(nxt, -1, sizeof(nxt));
        lev = 0;
        prv = -1;
    }
};
vector<Node> trie;

void add(int n)
{
    assert(n <= ((1 << L) - 1));
    int c = 0;
    for (int i = L - 1; ~i; i--)
    {
        int v = (n >> i) & 1;
        if (trie[c].nxt[v] == -1)
        {
            trie[c].nxt[v] = trie.size();
            trie.emplace_back();
            trie.back().prv = c;
        }
        c = trie[c].nxt[v];
        // cout << c << endl;
        assert(~c);
    }
    trie[c].lev += 1;
}
void del(int n)
{
    assert(n <= ((1 << L) - 1));
    int c = 0;
    for (int i = L - 1; ~i; i--)
    {
        int v = (n >> i) & 1;
        c = trie[c].nxt[v];
        assert(~c);
    }
    assert(trie[c].lev);
    trie[c].lev -= 1;
    if (trie[c].lev == 0)
    {
        int nxt = -1;
        while (trie[c].nxt[0] == -1 || trie[c].nxt[1] == -1)
        {
            nxt = c;
            c = trie[c].prv;
        }
        bool ok = false;
        if (~trie[c].nxt[0] && trie[c].nxt[0] == nxt)
        {
            trie[c].nxt[0] = -1;
            ok ^= true;
        }
        if (~trie[c].nxt[1] && trie[c].nxt[1] == nxt)
        {
            trie[c].nxt[1] = -1;
            ok ^= true;
        }
        assert(ok);
    }
}

int get(int n)
{
    assert(n <= ((1 << L) - 1));
    int c = 0, ret = 0;
    for (int i = L - 1; ~i; i--)
    {
        int v = (n >> i) & 1;
        ret <<= 1;
        if (trie[c].nxt[v] == -1)
        {
            ret |= (v ^ 1);
            c = trie[c].nxt[v ^ 1];
        }
        else
        {
            ret |= v;
            c = trie[c].nxt[v];
        }
        assert(~c);
    }
    return ret;
}

void run()
{
    int q;
    scanf("%d\n", &q);
    trie.emplace_back();
    add(0);
    while (q--)
    {
        char c;
        int v;
        scanf("%c %d\n", &c, &v);
        if (c == '?')
        {
            printf("%d\n", v ^ get(v ^ ((1 << L) - 1)));
        }
        else if (c == '+')
        {
            add(v);
        }
        else if (c == '-')
        {
            del(v);
        }
        else
        {
            assert(false);
        }
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}