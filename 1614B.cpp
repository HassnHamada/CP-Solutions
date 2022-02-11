#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
typedef long long int ll;

const int N = 2e5 + 10;
int ans[N], n;
pair<int, int> arr[N];

void run()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + n + 1, greater<pair<int, int>>());
    ll tot = 0;
    for (int i = 1; i <= n; i++)
    {
        ans[arr[i].second] = (i + 1) / 2 * (i & 1 ? 1 : -1);
        tot += 1ll * arr[i].first * ((i + 1) / 2);
    }
    cout << 2 * tot << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
}
// 101
// 110
// 111
// 0 7 7 0 2
// 0 7 0 0 2    9
//   7 0 0 2    9
//     7 7 5    19
//       0 2    2
//         2    2
int main(int argc, char const *argv[])
{
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
    return 0;
}