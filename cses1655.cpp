#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 2, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

struct Node
{
    int nxt[M];
    Node()
    {
        memset(nxt, -1, sizeof(nxt));
    }
};
vector<Node> trie;

void add(int n)
{
    int c = 0;
    for (int i = L - 1; ~i; i--)
    {
        assert(c != -1);
        int v = (n >> i) & 1;
        if (trie[c].nxt[v] == -1)
        {
            trie[c].nxt[v] = trie.size();
            trie.emplace_back();
        }
        c = trie[c].nxt[v];
    }
}

int get(int n)
{
    int c = 0, ret = 0;
    for (int i = L - 1; ~i; i--)
    {
        assert(c != -1);
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
    }
    return ret;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
        arr[i] ^= arr[i - 1];
    }
    trie.emplace_back();
    for (int i = 0; i <= n; i++)
    {
        add(arr[i]);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, arr[i] ^ get(~arr[i]));
    }
    printf("%d\n", ans);
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