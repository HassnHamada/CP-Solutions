#include <bits/stdc++.h>
// #pragma GCC optimize("-Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#define ll long long

using namespace std;

const int N = 1 << 17;
const ll min_num = 999999999999999;

void count_sort(vector<int> &p, vector<int> &c)
{
    int n = p.size();

    vector<int> cnt(n);
    for (auto x : c)
    {
        cnt[x]++;
    }

    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (auto x : p)
    {
        p_new[pos[c[x]]] = x;
        pos[c[x]]++;
    }

    p = p_new;
}
struct SEG
{
    pair<int, int> tre[N << 1];
    void build(int i, int s, int e, vector<int> &vec)
    {
        if (s == e)
        {
            tre[i].first = vec[s];
            tre[i].second = s;
            return;
        }
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        build(l, s, m, vec);
        build(r, m + 1, e, vec);
        if (tre[l].first < tre[r].first)
        {
            tre[i] = tre[l];
        }
        else
        {
            tre[i] = tre[r];
        }
    }

    pair<int, int> get(int qs, int qe, int i, int s, int e)
    {
        if (qs > e || qe < s)
        {
            return {INT32_MAX, -1};
        }
        if (s >= qs && e <= qe)
        {
            return tre[i];
        }
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        auto a = get(qs, qe, l, s, m), b = get(qs, qe, r, m + 1, e);
        if (a.first < b.first)
        {
            return a;
        }
        return b;
    }
} seg;

int main()
{
    freopen("hawara.in", "r", stdin);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = {s[i], i};
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
            {
                c[p[i]] = c[p[i - 1]];
            }
            else
            {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }

    for (int k = 0; (1 << k) < n; k++)
    {

        for (int i = 0; i < n; i++)
        {
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        count_sort(p, c);
        vector<int> c_new(n);
        c_new[p[0]] = 0;

        for (int i = 1; i < n; i++)
        {
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % n]};
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
            if (now == prev)
            {
                c_new[p[i]] = c_new[p[i - 1]];
            }
            else
            {
                c_new[p[i]] = c_new[p[i - 1]] + 1;
            }
        }
        c = c_new;
        k++;
    }
    vector<int> arr(n);
    for (int i = 1; i < n; i++)
    {
        arr[p[i]] = i;
    }
    seg.build(0, 0, n - 2, arr);

    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        auto res = seg.get(l - 1, r - k, 0, 0, n - 2);
        cout << res.second + 1 << endl;
    }
    return 0;
}
