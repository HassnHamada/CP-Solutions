#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1 << 19;
ll seg[N], n;

void build(int i = 0, int s = 0, int e = n - 1)
{
    if (s == e)
    {
        cin >> seg[i];
    }
    else
    {
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        build(l, s, m);
        build(r, m + 1, e);
        // seg[i] = seg[l]
    }
}

void pd(int i)
{
    seg[2 * i + 1] += seg[i];
    seg[2 * i + 2] += seg[i];
    seg[i] = 0;
}

void update(int us, int ue, int uv, int i = 0, int s = 0, int e = n - 1)
{
    if (us > e || ue < s)
    {
        return;
    }
    if (s >= us && e <= ue)
    {
        seg[i] += uv;
        return;
    }
    if (seg[i])
    {
        pd(i);
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    update(us, ue, uv, l, s, m);
    update(us, ue, uv, r, m + 1, e);
}

ll get(int p, int i = 0, int s = 0, int e = n - 1)
{
    if (p > e || p < s)
    {
        return -1;
    }
    if (s == e)
    {
        assert(s == p);
        return seg[i];
    }
    if (seg[i])
    {
        pd(i);
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    ll a = get(p, l, s, m);
    ll b = get(p, r, m + 1, e);
    assert(~a ^ ~b);
    // cout << s << " " << e << " " << a << " " << b << endl;
    return ~a ? a : b;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin >> n >> q;
    build();
    for (int i = 0; i < q; i++)
    {
        int o;
        cin >> o;
        if (o & 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            // cout << 1 << " " << a << " " << b << " " << u << endl;
            update(a - 1, b - 1, u);
        }
        else
        {
            int k;
            cin >> k;
            // cout << 2 << " " << k << endl;
            cout << get(k - 1) << endl;
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
