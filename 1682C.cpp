#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int n, arr[N];

pair<int, int> calc(int a)
{
    multiset<int> sss;
    for (int i = 0; i < n; i++)
    {
        sss.insert(arr[i]);
    }
    pair<int, int> ret = {0, 0}, tem = {0, 0};
    for (int i = 0, l = 0; i < a; i++)
    {
        auto it = sss.upper_bound(l);
        if (it == sss.end())
        {
            break;
        }
        tem.first = l = *it;
        ret.first += 1;
        sss.erase(it);
    }
    for (int l = 0; true;)
    {
        auto it = sss.upper_bound(l);
        if (it == sss.end())
        {
            break;
        }
        tem.second = l = *it;
        ret.second += 1;
        sss.erase(it);
    }
    for (int l = tem.first; true;)
    {
        auto it = sss.upper_bound(l);
        if (it == sss.end())
        {
            break;
        }
        tem.first = l = *it;
        ret.first += 1;
        sss.erase(it);
    }
    // assert(tem.first >= tem.second);
    if (tem.first < tem.second)
    {
        ret.first += 1;
    }
    if (tem.first > tem.second)
    {
        ret.second += 1;
    }
    return ret;
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    // int l = 1, h = n;
    // while (l < h)
    // {
    //     int m = (h + 1 - l) / 2 + l;
    //     pair<int, int> res = calc(m);
    //     // cout << m << " " << res.first << " " << res.second << endl;
    //     if (res.first == m && res.first <= res.second)
    //     {
    //         l = m;
    //     }
    //     else
    //     {
    //         h = m - 1;
    //     }
    // }
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        auto t = calc(i);
        // cout << i << " " << t.first << " " << t.second << endl;
        ans = max(ans, min(t.first, t.second));
    }
    printf("%d\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}