
#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
typedef long long int ll;

void gcd(ll &x, ll &y)
{
    ll g = __gcd(abs(x), abs(y));
    x /= g;
    y /= g;
}

void run()
{
    ll u, v, x = -1, y = 1;
    cin >> u >> v;
    if (u != v)
    {
        x = -u * u;
        y = (u + v) * (v - u) - x;
        gcd(x, y);
    }
    cout << x << " " << y << endl;
}

// (x * v + y * u) / (x + y)
// (u * v) / (u + v)
// x * v + u * u + v * u - x * u = u * v
// x * v - x * u = - u * u
// x * (v - u) = - u * u
// y = u + v - x

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
