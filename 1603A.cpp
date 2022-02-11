#include <bits/stdc++.h>
// #include <string>
#include <iostream>
using namespace std;
typedef long long int ll;

const int N = 1e5 + 10;

struct List
{
    int val = 0;
    List *nxt = nullptr, *prv = nullptr;
    void del()
    {
        if (this->prv != nullptr)
        {
            this->prv->nxt = this->nxt;
        }
        if (this->nxt != nullptr)
        {
            this->nxt->prv = this->prv;
        }
    }
} lst[N];

void dfs(List *c, int i)
{
    if (c->nxt == nullptr)
    {
        if (c->val % (i + 1))
        {
            c->del();
        }
    }
    else
    {
        dfs(c->nxt, i + 1);
        if (c->val % (i + 1))
        {
            c->del();
            if (c->nxt != nullptr)
            {
                dfs(c->nxt, i);
            }
        }
    }
}

void run()
{
    int n;
    cin >> n;
    lst[0].nxt = &lst[1];
    for (int i = 1; i <= n; i++)
    {
        cin >> lst[i].val;
        lst[i].prv = &lst[i - 1];
        if (i < n)
        {
            lst[i].nxt = &lst[i + 1];
        }
        else
        {
            lst[i].nxt = nullptr;
        }
    }
    List *c = lst;
    dfs(lst + 1, 1);
    cout << (lst[0].nxt == nullptr ? "YES\n" : "NO\n");
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}
