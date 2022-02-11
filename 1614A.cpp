#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
typedef long long int ll;

// const int N = 300, EMP = 0x0f0f0f0f;
// int grf[N][N], dst[N], n, m;

void run()
{
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> vec;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        if (v < l || v > r)
        {
            continue;
        }
        vec.push_back(v);
    }
    sort(vec.begin(), vec.end());
    ll tot = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        tot += vec[i];
        if (tot > k)
        {
            cout << i << endl;
            return;
        }
    }
    cout << vec.size() << endl;
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