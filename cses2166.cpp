#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1 << 19;
int n, q;
struct NODE
{
    ll tot, pre, suf;
    NODE(){};
    NODE(ll tot, ll pre, ll suf) : tot(tot), pre(pre), suf(suf){};
    void prn()
    {
        cout << tot << " " << pre << " " << suf << endl;
    }
} seg[N];

const NODE ZERO_NODE(0, 0, 0);

void build(int i = 0, int s = 0, int e = n - 1)
{
    if (s == e)
    {
        cin >> seg[i].tot;
        seg[i].suf = seg[i].pre = max(seg[i].tot, 0ll);
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    build(l, s, m);
    build(r, m + 1, e);
    seg[i].pre = max(seg[l].pre, seg[l].tot + seg[r].pre);
    seg[i].suf = max(seg[r].suf, seg[r].tot + seg[l].suf);
    seg[i].tot = seg[l].tot + seg[r].tot;
}
void update(int p, int v, int i = 0, int s = 0, int e = n - 1)
{
    if (p > e || p < s)
    {
        return;
    }
    if (s == e)
    {
        seg[i].tot = v;
        seg[i].suf = seg[i].pre = max(seg[i].tot, 0ll);
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    update(p, v, l, s, m);
    update(p, v, r, m + 1, e);
    seg[i].pre = max(seg[l].pre, seg[l].tot + seg[r].pre);
    seg[i].suf = max(seg[r].suf, seg[r].tot + seg[l].suf);
    seg[i].tot = seg[l].tot + seg[r].tot;
}

NODE get(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (qs > e || qe < s)
    {
        return ZERO_NODE;
    }
    if (s >= qs && e <= qe)
    {
        return seg[i];
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    NODE ln = get(qs, qe, l, s, m), rn = get(qs, qe, r, m + 1, e);
    return NODE(ln.tot + rn.tot, max(ln.pre, ln.tot + rn.pre), max(rn.suf, rn.tot + ln.suf));
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    cin >> n >> q;
    build();
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a & 1)
        {
            update(--b, c);
        }
        else
        {
            cout << get(--b, --c).pre << endl;
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}