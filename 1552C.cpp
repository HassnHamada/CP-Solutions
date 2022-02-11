#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;
const int N = 210;
int str[N], fin[N], arr[N];

int skp(int n, int s)
{
    for (int i = 1; i <= 2 * n; i++)
    {
        if (str[i] || fin[i])
        {
            continue;
        }
        if (!s--)
        {
            return i;
        }
    }
    assert(false);
    return -1;
}

int add(int s, int e, int n)
{
    int ret = 0;
    for (int i = 0; i < 2 * n; i += 2)
    {
        ret += (arr[i] < s && arr[i + 1] > s && arr[i + 1] < e) | (arr[i] > s && arr[i] < e && arr[i + 1] > e);
    }
    return ret;
}

void run()
{
    int n, k, ans = 0;
    cin >> n >> k;
    memset(str + 1, 0, 2 * n * sizeof(str[0]));
    memset(fin + 1, 0, 2 * n * sizeof(fin[0]));
    for (int i = 0, u, v; i < k; i++)
    {
        cin >> u >> v;
        if (u > v)
        {
            swap(u, v);
        }
        arr[2 * i] = u;
        arr[2 * i + 1] = v;
        str[u] = fin[v] = 1;
        ans += add(u, v, i);
    }
    int m = n - k;
    while (m)
    {
        int s = m / 2;
        int u = skp(n, s), v = skp(n, m + s);
        int i = n - m--;
        str[u] = fin[v] = 1;
        arr[2 * i] = u;
        arr[2 * i + 1] = v;
        ans += add(u, v, i);
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
