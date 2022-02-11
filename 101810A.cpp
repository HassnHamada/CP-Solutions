#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e5 + 10;
struct Node
{
    int l, r, v;
    bool operator<(const Node &other) const
    {
        return this->l < other.l;
    }
} arr[N];

void run()
{
    int m, k;
    cin >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].l >> arr[i].r >> arr[i].v;
    }
    sort(arr, arr + m);
    int n = m;
    for (int i = 0, s = 1; i < m; s = arr[i++].r + 1)
    {
        if (s < arr[i].l)
        {
            arr[n++] = {s, arr[i].l - 1, 0};
        }
    }
    sort(arr, arr + n);
    if (arr[n - 1].r != (int)(1e9))
    {
        arr[n] = {arr[n - 1].r, (int)(1e9), 0};
        n += 1;
    }
    ll ans = 0;
    for (ll i = 0, j = 0, s = 0, c = 0; i < n; i++)
    {
        c += 1ll * (arr[i].r - arr[i].l + 1) * arr[i].v;
        s += arr[i].r - arr[i].l + 1;
        if (s > k)
        {
            int e = s - k, f = 0;
            ll rem = 1ll * e * arr[i].v, rem1 = rem, rem2 = 0;
            while (e)
            {
                int v = arr[j].r - arr[j].l + 1;
                if (e >= v)
                {
                    rem2 += 1ll * v * arr[j++].v;
                    rem = min(rem, rem1 - 1ll * (f += v) * arr[i].v + rem2);
                    e -= v;
                }
                else
                {
                    rem2 += 1ll * e * arr[j].v;
                    rem = min(rem, rem1 - 1ll * (f += e) * arr[i].v + rem2);
                    arr[j].l += e;
                    assert(arr[j].l <= arr[j].r);
                    break;
                }
            }
            ans = max(ans, c - rem);
            c -= rem2;
            s = k;
        }
        ans = max(ans, c);
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}