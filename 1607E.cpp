#include <bits/stdc++.h>
// #include <string>
#include <iostream>
using namespace std;
// typedef long long int ll;

void run()
{
    int n, m, l = 0, r = 0, d = 0, u = 0;
    string s;
    cin >> n >> m >> s;
    pair<int, int> ans = {0, 0};
    for (auto &&i : s)
    {
        ans.second -= (i == 'L' ? 1 : 0);
        ans.second += (i == 'R' ? 1 : 0);
        ans.first += (i == 'D' ? 1 : 0);
        ans.first -= (i == 'U' ? 1 : 0);
        if (ans.second > 0)
        {
            assert(ans.second <= r + 1);
            int t = max(r, ans.second);
            if (t + l == m)
            {
                ans.second -= (i == 'L' ? -1 : 0);
                ans.second += (i == 'R' ? -1 : 0);
                ans.first += (i == 'D' ? -1 : 0);
                ans.first -= (i == 'U' ? -1 : 0);
                break;
            }
            r = t;
        }
        else
        {
            assert(abs(ans.second) <= l + 1);
            int t = max(l, abs(ans.second));
            if (t + r == m)
            {
                ans.second -= (i == 'L' ? -1 : 0);
                ans.second += (i == 'R' ? -1 : 0);
                ans.first += (i == 'D' ? -1 : 0);
                ans.first -= (i == 'U' ? -1 : 0);
                break;
            }
            l = t;
        }
        if (ans.first > 0)
        {
            assert(ans.first <= d + 1);
            int t = max(d, ans.first);
            if (t + u == n)
            {
                ans.second -= (i == 'L' ? -1 : 0);
                ans.second += (i == 'R' ? -1 : 0);
                ans.first += (i == 'D' ? -1 : 0);
                ans.first -= (i == 'U' ? -1 : 0);
                break;
            }
            d = t;
        }
        else
        {
            assert(abs(ans.first) <= u + 1);
            int t = max(u, abs(ans.first));
            if (t + d == n)
            {
                ans.second -= (i == 'L' ? -1 : 0);
                ans.second += (i == 'R' ? -1 : 0);
                ans.first += (i == 'D' ? -1 : 0);
                ans.first -= (i == 'U' ? -1 : 0);
                break;
            }
            u = t;
        }
        // cout << i << " " << l << " " << r << " " << d << " " << u << endl;
    }
    cout << u + 1 << " " << l + 1 << endl;
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

// LUURRDDLLLUU
// ***
// ***
// ***
// ***