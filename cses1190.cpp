#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
typedef long long int ll;
// #include <chrono>
// using namespace std::chrono;

const int N = 1 << 18;
int n, arr[N];

struct Node
{
    ll l, r, t, ans;
} seg[N << 1], EMP{0, 0, 0, 0};

void merge(Node &out, Node &l, Node &r)
{
    out.l = max(l.l, l.t + r.l);
    out.r = max(r.r, r.t + l.r);
    out.t = l.t + r.t;
    out.ans = max({l.ans, r.ans, l.r + r.l});
    // cout << out.l << " " << out.r << " " << out.t << " " << out.ans << endl;
    assert(out.ans >= max({out.l, out.r, out.t}));
}

void build(int i = 0, int s = 0, int e = n - 1)
{
    if (s == e)
    {
        seg[i] = {max(arr[s], 0), max(arr[s], 0), arr[s], max(arr[s], 0)};
        // cout << s << " ";
        // cout << seg[i].ans << endl;
    }
    else
    {
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        build(l, s, m);
        build(r, m + 1, e);
        merge(seg[i], seg[l], seg[r]);
    }
    // cout << s << " " << e << " " << seg[i].v << endl;
}

Node get(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (qs > e || qe < s)
    {
        return EMP;
    }
    if (s >= qs && e <= qe)
    {
        return seg[i];
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    Node ln = get(qs, qe, l, s, m),
         rn = get(qs, qe, r, m + 1, e),
         ret = EMP;
    merge(ret, ln, rn);
    return ret;
}

void update(int k, int i = 0, int s = 0, int e = n - 1)
{
    // cout << s << " " << e << endl;
    if (k > e || k < s)
    {
        return;
    }
    if (s == e)
    {
        // cout << s << endl;
        assert(s == k);
        seg[i] = {max(arr[s], 0), max(arr[s], 0), arr[s], max(arr[s], 0)};
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    update(k, l, s, m);
    update(k, r, m + 1, e);
    merge(seg[i], seg[l], seg[r]);
}

void run()
{
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build();
    // cout << "dasd" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         cout << i << " " << j + 1 << " " << get(i, j).ans << endl;
    //     }
    // }
    while (m--)
    {
        int k, x;
        cin >> k >> x;
        arr[--k] = x;
        update(k);
        cout << get(0, n - 1).ans << endl;
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}