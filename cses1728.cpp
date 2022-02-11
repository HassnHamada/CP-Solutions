#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 1e2 + 10;
double arr[N], inv[N][N];

// 7 2
// 0 0
// 1 1
// 2 2
// 3 2
// 4 2
// 5 2
// 6 2

double calc(int a, int b)
{
    int m = min(a, b);
    double ret = m * (m - 1) / 2;
    if (a > b)
    {
        ret += b * (a - b);
    }
    // cout << a << " " << b << " " << ret << endl;
    return ret / a / b;
}

void run()
{
    int n;
    cin >> n;
    double exp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < i; j++)
        {
            // inv[i][j] = calc(arr[i], arr[j]) + (j ? inv[i][j - 1] : 0);
            // inv[i][j] = calc(arr[j], arr[i]);
            exp += calc(arr[j], arr[i]);
            // cout << i << " " << j << " " << calc(arr[i], arr[j]) << endl;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << inv[i][j] << " \n"[j + 1 == n];
    //     }
    // }
    cout << exp << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         exp += inv[i][j];
    //     }
    // }
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(6) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}