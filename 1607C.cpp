#include <bits/stdc++.h>
// #include <set>
// #include <iostream>
using namespace std;
// typedef long long int ll;

// const int N = 26;
// int arr[N];

void run()
{
    int n;
    cin >> n;
    multiset<int> sss;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        sss.insert(v);
    }
    int ans = INT32_MIN, f = 0;
    while (sss.size())
    {
        int r = *sss.begin() - f;
        sss.erase(sss.begin());
        ans = max(ans, r);
        f += r;
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
