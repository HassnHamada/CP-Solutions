#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 450, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
// ll area[N];

struct Point
{
    ll x, y;
    Point() {}
    Point(ll x, ll y)
    {
        this->x = x;
        this->y = y;
    }
    Point operator-(Point other)
    {
        return Point(other.x - x, other.y - y);
    }
    ll operator*(Point other)
    {
        return x * other.y - y * other.x;
    }
} arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &arr[i].x, &arr[i].y);
    }
    ll tot = 0;
    for (int i = 1; i < n - 1; i++)
    {
        tot += (arr[0] - arr[i]) * (arr[0] - arr[i + 1]);
    }
    // cout << tot / 2.0 << endl;
    ll ans = INT64_MAX;
    for (int i = 0; i < n; i++)
    {
        ll a1 = 0;
        for (int j = 0; i + j + 2 < n && j < n - 3; j++)
        {
            // for (int k = i + 1; k < i + j + 2; k++)
            // {
            // }
            a1 += (arr[i] - arr[i + j + 1]) * (arr[i] - arr[i + j + 2]);
            ll a2 = tot - a1;
            // cout << i << " " << i + j + 2 << " " << a1 / 2.0 << " " << a2 / 2.0 << endl;
            ans = min({ans, abs(tot - 4 * a1), abs(tot - 4 * a2)});
            // cout << ans << endl;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}