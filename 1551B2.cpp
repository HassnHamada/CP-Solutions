#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
// const int N = 1e6 + 10;
int arr[N], frq[N], ans[N], nxt[N], col[N];

void run()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        frq[arr[i]]++;
    }
    int nn = n;
    for (int i = 0; i < n; i++)
    {
        if (frq[arr[i]] >= k && nxt[arr[i]] < k)
        {
            ans[i] = ++nxt[arr[i]];
            if (nxt[arr[i]] == k)
            {
                nn -= frq[arr[i]];
            }
        }
    }
    int m = nn / k;
    memset(nxt, 0, (n + 1) * sizeof(nxt[0]));
    for (int i = 0; m && i < n; i++)
    {
        if (frq[arr[i]] < k)
        {
            while (nxt[arr[i]] == 0 || col[nxt[arr[i]]] == m)
            {
                nxt[arr[i]]++;
            }
            if (nxt[arr[i]] > k)
            {
                continue;
            }
            ans[i] = nxt[arr[i]];
            col[nxt[arr[i]]++]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i + 1 == n];
    }
    memset(frq, 0, (n + 1) * sizeof(frq[0]));
    memset(col, 0, (n + 1) * sizeof(col[0]));
    memset(nxt, 0, (n + 1) * sizeof(nxt[0]));
    memset(ans, 0, (n + 1) * sizeof(ans[0]));
    memset(arr, 0, (n + 1) * sizeof(arr[0]));
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
