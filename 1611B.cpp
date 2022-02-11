// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
typedef long long int ll;

ll calc(ll a, ll b)
{
    // cout << a << " " << b << endl;
    assert(a >= 0 && b >= 0);
    if (a > b)
    {
        swap(a, b);
    }
    if (a == 0 || a + b < 4)
    {
        return 0;
    }
    if (a == 1 || (a == 2 && b < 6))
    {
        return 1;
    }
    ll r = min((b - a) / 3, a);
    if (r == 0)
    {
        r = a / 2;
        return r + calc(a - 2 * r, b - 2 * r);
    }
    return r + calc(a - r, b - 3 * r);
    // if(a == 2 && )
    // ll n1 = min(a, b / 3) / 2, n2 = a / 4;
    // return max(n1 + calc(a - n1, b - 3 * n1), n2 + calc(a - 2 * n2, b - 2 * n2));
}

void run()
{
    int a, b;
    cin >> a >> b;
    cout << calc(a, b) << endl;
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