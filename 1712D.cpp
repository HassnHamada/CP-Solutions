#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 18, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], srt[N], arr2[N];
set<pair<int, int>> sss;

int n, k;
pair<int, int> tre[1 << M];

void build(int i = 0, int s = 0, int e = n - 2)
{
    if (s == e)
    {
        tre[i] = {arr2[s], arr2[s]};
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    build(l, s, m);
    build(r, m + 1, e);
    tre[i].first = min(tre[l].first, tre[r].first);
    tre[i].second = max(tre[l].second, tre[r].second);
}

void update(int q, int i = 0, int s = 0, int e = n - 2)
{
    if (q < s || q > e)
    {
        return;
    }
    if (s == e)
    {
        tre[i] = {arr2[s], arr2[s]};
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    update(q, l, s, m);
    update(q, r, m + 1, e);
    tre[i].first = min(tre[l].first, tre[r].first);
    tre[i].second = max(tre[l].second, tre[r].second);
}

pair<int, int> get(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (qs > e || qe < s)
    {
        return {INF, -1};
    }
    if (s >= qs && e <= qe)
    {
        return tre[i];
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    auto lr = get(qs, qe, l, s, m), rr = get(qs, qe, r, m + 1, e);
    return {min(lr.first, rr.first), max(lr.second, rr.second)};
}

void solve(int s, int e, vector<int> &out)
{
    if (s < e)
    {
        auto ret = get(s, e);
        out.push_back(ret.first);
        solve(s, ret.second - 1, out);
        solve(ret.second + 1, e, out);
    }
}

void run()
{
    sss.clear();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        sss.insert({arr[i], i});
    }
    for (auto &&i : sss)
    {
        if (--k == 0)
        {
            break;
        }
        arr[i.second] = 1e9;
    }
    for (int i = 0; i < n - 1; i++)
    {
        arr2[i] = min(arr[i], arr[i + 1]);
    }

    int ans = 0;
    build();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == (int)1e9)
        {
            continue;
        }
        int t = arr[i];
        arr[i] = 1e9;
        if (i)
        {
            arr2[i - 1] = min(arr[i - 1], arr[i]);
            update(i - 1);
        }
        arr2[i] = min(arr[i], arr[i + 1]);
        update(i);
        auto res = get(0, n - 1);
        ans = max(ans, min(2 * res.first, res.second));
        arr[i] = t;
        if (i)
        {
            arr2[i - 1] = min(arr[i - 1], arr[i]);
            update(i - 1);
        }
        arr2[i] = min(arr[i], arr[i + 1]);
        update(i);
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