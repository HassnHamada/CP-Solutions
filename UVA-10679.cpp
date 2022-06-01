#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, M = 1e3 + 5, MOD = 1e9 + 7, HV = 151;
char str[N], pat[M], ans[M];
// int ppp[N];

struct Trie
{
    char val;
    vector<int> id;
    map<char, Trie> nxt;
    void clear()
    {
        nxt.clear();
    }
    Trie *add(char c)
    {
        if (nxt.find(c) == nxt.end())
        {
            nxt.emplace(c, Trie{c});
        }
        return &nxt[c];
    }
    Trie *match(char c)
    {
        if (nxt.find(c) == nxt.end())
        {
            return nullptr;
        }
        return &nxt[c];
    }
    void prn(string &prv)
    {
        for (auto &&i : nxt)
        {
            if (i.first == '\0')
            {
                cout << prv << endl;
            }
            else
            {
                prv.push_back(i.first);
                i.second.prn(prv);
                prv.pop_back();
            }
        }
    }
    void prn()
    {
        string s;
        this->prn(s);
    }
} trie{-1};

void run()
{
    int n;
    scanf("%s%d", pat, &n);
    memset(ans, 'n', n * sizeof(ans[0]));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        Trie *cur = &trie;
        for (int i = 0; str[i]; i++)
        {
            cur = cur->add(str[i]);
        }
        cur->id.push_back(i);
    }
    for (int i = 0; pat[i]; i++)
    {
        Trie *cur = &trie;
        char *c = pat + i;
        while (cur)
        {
            // cout << *c << endl;
            for (auto &&j : cur->id)
            {
                ans[j] = 'y';
            }
            cur = cur->match(*c++);
            // c += 1;
        }
        // cout << endl;
    }
    // cout << "dasdas\n";
    for (int i = 0; i < n; i++)
    {
        printf("%c\n", ans[i]);
    }
    // trie.prn();
    trie.clear();
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}