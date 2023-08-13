// #include <bits/stdc++.h>
#include <assert.h>
#include <numeric>
// using namespace std;
typedef long long ll;

const int N = 1 << 18;

int arr[N], seg[N << 1];

int n;

void build(int i = 0, int s = 0, int e = n - 1)
{
    if (s == e)
    {
        seg[i] = arr[s];
    }
    else
    {
        int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
        build(l, s, m);
        build(r, m + 1, e);
        seg[i] = seg[l] & seg[r];
    }
}

int get(int qs, int qe, int i = 0, int s = 0, int e = n - 1)
{
    if (qs > e || qe < s)
    {
        return -1;
    }
    if (s >= qs && e <= qe)
    {
        return seg[i];
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    return get(qs, qe, l, s, m) & get(qs, qe, r, m + 1, e);
}

int bs(int t, int s, int e)
{
    while (s < e)
    {
        int m = s + (e - s) / 2;
        int v = get(s, m);
        if (v == t)
        {
            e = m;
        }
        else if (v > t)
        {
            s = m + 1;
        }
        else
        {
            assert(false);
        }
    }
    assert(s == e);
    return s;
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    build();
    int t = std::reduce(arr, arr + n, -1, [](int a, int b)
                        { return a & b; });
    int ans = 1, s = 0, e = n - 1;
    while (t == 0)
    {
        int m = bs(t, s, e);
        if (m == e)
        {
            break;
        }
        assert(get(s, m) == t);
        if (get(m + 1, e) ^ t)
        {
            break;
        }
        s = m + 1;
        ans++;
    }
    printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}