#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 2e5 + 10;
int aaa[N], bbb[N];

bool ok(int n, int sz)
{
    int c = 0;
    for (int i = 0; i < sz; i++)
    {
        c += (bbb[i] >= c && aaa[i] >= n - c - 1 ? 1 : 0);
    }
    return c >= n;
}

void run()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aaa[i] >> bbb[i];
    }
    int l = 1, h = n;
    while (l < h)
    {
        // cout << l << " " << h << endl;
        int m = l + (h - l + 1) / 2;
        if (ok(m, n))
        {
            l = m;
        }
        else
        {
            h = m - 1;
        }
    }
    cout << l << endl;
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