#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e5 + 10;
int arr[N], srt[N << 1];

struct BIT
{
    int tre[N << 1];
    void init()
    {
        memset(tre, 0, sizeof(tre));
    }
    void add(int pos, int val)
    {
        for (++pos; pos <= (N << 1); pos += (pos & (-pos)))
        {
            tre[pos - 1] += val;
        }
    }
    int get(int pos)
    {
        int ret = 0;
        for (++pos; pos; pos -= (pos & (-pos)))
        {
            ret += tre[pos - 1];
        }
        return ret;
    }
} bit;

void run()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        srt[2 * i] = arr[i];
        srt[2 * i + 1] = arr[i] - 1;
    }
    sort(srt, srt + 2 * n);
    int m = unique(srt, srt + 2 * n) - srt;
    for (int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(srt, srt + m, arr[i]) - srt;
    }
    ll ans = 0;
    bit.init();
    for (int i = 0; i < n; i++)
    {
        int l = bit.get(arr[i] - 1), h = i - bit.get(arr[i]);
        ans += min(l, h);
        bit.add(arr[i], 1);
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
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
