#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
typedef long long int ll;

struct Vec
{
    ll x, y;
    ll operator*(Vec &other)
    {
        return this->x * other.y - this->y * other.x;
    }
};

void run()
{
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    // if (a > c)
    // {
    //     swap(a, c);
    //     swap(b, d);
    // }
    Vec v1 = {c - a, d - b}, v2 = {e - a, f - b};
    ll res = v2 * v1;
    if (res)
    {
        cout << (res > 0 ? "RIGHT\n" : "LEFT\n");
    }
    else
    {
        cout << "TOUCH\n";
    }
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}