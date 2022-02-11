#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 2e5 + 10;
int arr[N], srt[N], frq[2][N], n;

bool work()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        srt[i] = arr[i];
    }
    sort(srt, srt + n);
    for (int i = 0; i < n; i++)
    {
        int l = lower_bound(srt, srt + n, arr[i]) - srt,
            h = upper_bound(srt, srt + n, arr[i]) - srt;
        int sz = h - l;
        int o = sz / 2, e = sz / 2, j = i & 1;
        (sz & l & 1 ? o : e)++;
        if (frq[j][arr[i]]++ == (j ? o : e))
        {
            return false;
        }
        assert(frq[j][arr[i]] <= (j ? o : e));
    }
    return true;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cout << (work() ? "YES\n" : "NO\n");
        memset(frq, 0, sizeof(frq));
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
