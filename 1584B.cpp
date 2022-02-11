
#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

// 0 1 -> 0
// 1 0 -> 0
// 1 1 -> 1
// 1 2 -> 1
// 2 1 -> 1
// 2 2 -> 2

int calc(int n, int m)
{
    // cout << n << " " << m << endl;
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (n == 1 && m == 1)
    {
        return 1;
    }
    if (n <= 2 && m <= 2)
    {
        return n + m - 2;
    }
    if (n > m)
    {
        swap(n, m);
    }
    return m / 3 * n + calc(n, m % 3);
}

void run()
{
    int n, m;
    cin >> n >> m;
    cout << calc(n, m) << endl;
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
