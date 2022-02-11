#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1 << 19;
ll seg[N], arr[N];

void build(int i, int s, int e)
{
    if (s == e)
    {
        seg[i] = arr[s];
        return;
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    build(l, s, m);
    build(r, m + 1, e);
    seg[i] = min(seg[l], seg[r]);
}

ll get(int qs, int qe, int i, int s, int e)
{
    if (qs > e || qe < s)
    {
        return INT64_MAX;
    }
    if (s >= qs && e <= qe)
    {
        return seg[i];
    }
    int l = 2 * i + 1, r = l + 1, m = s + (e - s) / 2;
    return min(get(qs, qe, l, s, m), get(qs, qe, r, m + 1, e));
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", arr + i);
        arr[i] += arr[i - 1];
    }
    build(0, 1, n);
    ll ans = arr[a];
    for (int i = a + 1; i <= n; i++)
    {
        ll v = get(max(1, i - b), i - a, 0, 1, n);
        ans = max(ans, arr[i] - (i <= b ? min(0ll, v) : v));
    }
    printf("%lld\n", ans);

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}