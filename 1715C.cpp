#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 17, M = 6, MOD = 1e9 + 9, HV = 151, INF = 0x3f3f3f3f;

int arr[N], srt[N];
int n, m;

ll ans;

map<int, pair<set<int>, set<int, greater<int>>>> mmm;

void add(int i)
{
    auto lt = mmm[arr[i]].second.upper_bound(i),
         ut = mmm[arr[i]].first.upper_bound(i);
    int l = lt == mmm[arr[i]].second.end() ? -1 : *lt,
        u = ut == mmm[arr[i]].first.end() ? n : *ut;
    assert(l <= i);
    assert(u >= i);
    ans += (i - l) * (u - i);
}

void del(int i)
{
    auto lt = mmm[arr[i]].second.upper_bound(i),
         ut = mmm[arr[i]].first.upper_bound(i);
    int l = lt == mmm[arr[i]].second.end() ? -1 : *lt,
        u = ut == mmm[arr[i]].first.end() ? n : *ut;
    assert(l <= i);
    assert(u >= i);
    ans -= (i - l) * (u - i);
}

void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        mmm[arr[i]].first.insert(i);
        mmm[arr[i]].second.insert(i);
    }
    for (int i = 0; i < n; i++)
    {
        add(i);
        // printf("%lld\n", ans);
    }
    while (m--)
    {
        int i, x;
        scanf("%d%d", &i, &x);
        del(i - 1);
        printf("%lld\n", ans);
        mmm[arr[i - 1]].first.erase(i - 1);
        mmm[arr[i - 1]].second.erase(i - 1);
        arr[i - 1] = x;
        mmm[arr[i - 1]].first.insert(i - 1);
        mmm[arr[i - 1]].second.insert(i - 1);
        add(i - 1);
        printf("%lld\n", ans);
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}