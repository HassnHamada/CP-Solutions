#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 1e5 + 10, Q = 1000, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];

struct Query
{
    int l, r, i;
    bool operator<(const Query &other) const
    {
        if (this->l / Q == other.l / Q)
        {
            return this->r < other.r;
        }
        return this->l / Q < other.l / Q;
    }
} queries[M];

int s, e, usd[N], curAns;
deque<int> pre, suf;

void add(int i)
{
    // cerr << "Add " << i << endl;
    assert(i == s || i == e - 1);
    if (i == s)
    {
        if (str[i] == '(')
        {
            if (suf.empty())
            {
                pre.push_front(i);
            }
            else
            {
                assert(usd[i] == -1);
                assert(usd[suf.front()] == -1);
                usd[i] = suf.front();
                usd[suf.front()] = i;
                suf.pop_front();
                curAns += 2;
            }
        }
        else
        {
            assert(str[i] == ')');
            suf.push_front(i);
        }
    }
    else
    {
        if (str[i] == '(')
        {
            pre.push_back(i);
        }
        else
        {
            assert(str[i] == ')');
            if (pre.empty())
            {
                suf.push_back(i);
            }
            else
            {
                assert(usd[i] == -1);
                assert(usd[pre.back()] == -1);
                usd[i] = pre.back();
                usd[pre.back()] = i;
                pre.pop_back();
                curAns += 2;
            }
        }
    }
}

void del(int i)
{
    // cerr << "Del " << i << endl;
    assert(i == s - 1 || i == e);
    if (i == s - 1)
    {
        if (str[i] == '(')
        {
            if (usd[i] == -1)
            {
                assert(pre.front() == i);
                pre.pop_front();
            }
            else
            {
                int j = usd[i];
                assert(usd[j] == i);
                usd[i] = usd[j] = -1;
                assert(str[j] == ')');
                assert(suf.empty() || suf.front() > j);
                suf.push_front(j);
                curAns -= 2;
            }
        }
        else
        {
            assert(str[i] == ')');
            assert(usd[i] == -1);
            suf.pop_front();
        }
    }
    else
    {
        if (str[i] == '(')
        {
            assert(usd[i] == -1);
            pre.pop_back();
        }
        else
        {
            assert(str[i] == ')');
            if (usd[i] == -1)
            {
                assert(suf.back() == i);
                suf.pop_back();
            }
            else
            {
                int j = usd[i];
                assert(usd[j] == i);
                usd[i] = usd[j] = -1;
                assert(str[j] == '(');
                assert(pre.empty() || pre.back() < j);
                pre.push_back(j);
                curAns -= 2;
            }
        }
    }
}

void updateSE(int qs, int qe)
{
    while (e < qe + 1)
    {
        add(e++);
    }
    while (s > qs)
    {
        add(--s);
    }
    while (s < qs)
    {
        del(s++);
    }
    while (e > qe + 1)
    {
        del(--e);
    }
}

void run()
{
    scanf("%s", str);
    // int m, n = strlen(str);
    int m;
    memset(usd, -1, sizeof(usd));
    scanf("%d", &m);
    vector<int> ans(m);
    for (int i = 0; i < m; i++)
    {
        queries[i].i = i;
        scanf("%d%d", &queries[i].l, &queries[i].r);
    }
    sort(queries, queries + m);
    for (int i = 0; i < m; i++)
    {
        // cerr << queries[i].l << " " << queries[i].r << "\n";
        updateSE(queries[i].l - 1, queries[i].r - 1);
        ans[queries[i].i] = curAns;
        // cerr << curAns << endl;
    }
    for (auto &&i : ans)
    {
        printf("%d\n", i);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}