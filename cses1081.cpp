#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;
// #include <chrono>
// using namespace std::chrono;

const int N = 1 << 20;
int frq[N], ans;

void maxAns(int i)
{
    if (frq[i]++)
    {
        ans = max(ans, i);
    }
}

void div(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i != n)
            {
                maxAns(n / i);
            }
            maxAns(i);
        }
    }
}

void run()
{
    int n;
    cin >> n;
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        div(v);
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}