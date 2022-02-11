#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

void run()
{
    int n, ans = -1;
    cin >> n;
    if (n % 2)
    {
        while (n)
        {
            if (n % 2 == 0)
            {
                // cout << n << endl;
                ans = n < 10 ? 1 : 2;
            }
            n /= 10;
        }
    }
    else
    {
        ans = 0;
    }
    cout << ans << endl;
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