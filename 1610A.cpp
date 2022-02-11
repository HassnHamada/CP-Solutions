#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

void run()
{
    int n, m, ans = 2;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        ans = 0;
    }
    else if (n == 1 || m == 1)
    {
        ans = 1;
    }
    cout << ans << endl;
}

// 012
// 123

// 123
// 012

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