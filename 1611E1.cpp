// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
typedef long long int ll;

const int N = 2e5 + 10;
int arr[N];

void run()
{
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll val = 0;
    pair<int, int> ans = {-1, -1};
    for (int i = 0, j = 0; j < n; j++)
    {
        val += arr[j];
        while (i <= j && val + s < 0)
        {
            val -= arr[i++];
        }
        if (val && j - i >= ans.second - ans.first)
        {
            ans = {i + 1, j + 1};
        }
    }
    if (~ans.first)
    {
        cout << ans.first << " " << ans.second << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

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