#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 10, M = 1e6 + 10, Q = 548, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

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
} qqq[M];

int arr[N], pos[N], ans[M];

set<int> nums_l;
set<int, greater<int>> nums_h;
set<tuple<int, int, int>> stk;
int add_call_count = 0, del_call_count = 0;

void add(int idx)
{
    add_call_count += 1;
    // cout << "call add " << idx << endl;
    auto l = nums_l.upper_bound(arr[idx]),
         h = nums_h.upper_bound(arr[idx]);
    if (l != nums_l.end())
    {
        stk.emplace(*l - arr[idx], idx, pos[*l]);
    }
    if (h != nums_h.end())
    {
        stk.emplace(arr[idx] - *h, idx, pos[*h]);
    }
    // if (l == nums_l.end())
    // {
    //     if (h == nums_h.end())
    //     {
    //         // pass
    //     }
    //     else
    //     {
    //         stk.emplace(arr[idx] - *h, idx, pos[*h]);
    //     }
    // }
    // else if (h == nums_h.end())
    // {
    //     assert(l != nums_l.end());
    //     stk.emplace(*l - arr[idx], idx, pos[*l]);
    // }
    // else
    // {
    //     if (*l - arr[idx] < arr[idx] - *h)
    //     {
    //         stk.emplace(*l - arr[idx], idx, pos[*l]);
    //     }
    //     else
    //     {
    //         stk.emplace(arr[idx] - *h, idx, pos[*h]);
    //     }
    // }
    nums_l.insert(arr[idx]);
    nums_h.insert(arr[idx]);
}

void del(int idx)
{
    del_call_count += 1;
    nums_l.erase(arr[idx]);
    nums_h.erase(arr[idx]);
}

int s, e;

void clean()
{
    while (!stk.empty())
    {
        auto [v, i, j] = *stk.begin();
        if (i < s || i >= e)
        {
            if (j < s || j >= e)
            {
                stk.erase(stk.begin());
            }
            else
            {
                stk.erase(stk.begin());
                add(j);
            }
        }
        else if (j < s || j >= e)
        {
            stk.erase(stk.begin());
            add(i);
        }
        else
        {
            break;
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
    clean();
}

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        pos[arr[i]] = i;
    }
    for (int i = 0; i < q; i++)
    {
        qqq[i].i = i;
        scanf("%d%d", &qqq[i].l, &qqq[i].r);
    }
    sort(qqq, qqq + q);
    for (int i = 0; i < q; i++)
    {
        updateSE(qqq[i].l - 1, qqq[i].r - 1);
        // cout << i << " " << nums_l.size() << " " << nums_h.size() << " " << stk.size() << endl;
        cout << i << " " << stk.size() << endl;
        cout << i << " " << qqq[i].l / Q << " " << qqq[i].r << endl;
        auto [v, _, __] = *stk.begin();
        ans[qqq[i].i] = v;
    }
    cout << add_call_count << " " << del_call_count << endl;
    // for (int i = 0; i < q; i++)
    // {
    //     printf("%d\n", ans[i]);
    // }
}

int main()
{
    freopen("_input.txt", "r", stdin);
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
