#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 10, M = 26, MOD = 1e9, HV = 151, INF = 0x3f3f3f3f;

struct Node
{
    int nxt[M], cnt = 0;
    Node()
    {
        memset(nxt, -1, sizeof(nxt));
    }
};
vector<Node> trie;

void add(char *str)
{
    int c = 0;
    for (int i = 0; str[i]; i++)
    {
        int v = str[i] - 'a';
        if (trie[c].nxt[v] == -1)
        {
            trie[c].nxt[v] = trie.size();
            trie.emplace_back();
        }
        c = trie[c].nxt[v];
    }
    trie[c].cnt++;
}

int get(char *str)
{
    int c = 0;
    for (int i = 0; str[i]; i++)
    {
        int v = str[i] - 'a';
        assert(trie[c].nxt[v] != -1);
        c = trie[c].nxt[v];
    }
    assert(trie[c].cnt);
    return trie[c].cnt;
}

char buf[N][M >> 1];

void run()
{
    int n, c;
    scanf("%d%d", &n, &c);
    trie.emplace_back();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", (char *)(buf + i));
        int j = find((char *)(buf + i), (char *)(buf + i) + c, '*') - (char *)(buf + i);
        for (int k = 0; k < M; k++)
        {
            buf[i][j] = k + 'a';
            add((char *)(buf + i));
        }
        buf[i][j] = '*';
    }
    pair<string, int> ans = {"", -1};
    for (int i = 0; i < n; i++)
    {
        int j = find((char *)(buf + i), (char *)(buf + i) + c, '*') - (char *)(buf + i);
        for (int k = 0; k < M; k++)
        {
            buf[i][j] = k + 'a';
            int ret = get((char *)(buf + i));
            if (ret > ans.second)
            {
                ans = {(char *)(buf + i), ret};
            }
            else if (ret == ans.second)
            {
                if (strcmp((char *)(buf + i), ans.first.c_str()) < 0)
                {
                    ans = {(char *)(buf + i), ret};
                }
            }
        }
    }
    assert(ans.second != -1);
    printf("%s %d\n", ans.first.c_str(), ans.second);
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