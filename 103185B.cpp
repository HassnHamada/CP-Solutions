// #include <bits/stdc++.h>
#include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 1e5 + 20;
int arr[N], dp[N];

void run()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "N\n";
        return;
    }
    for (int i = 0, v; i < n; i++)
    {
        cin >> v;
        arr[v] += 1;
    }
    for (int i = 0; i < N - 1; i++)
    {
        arr[i + 1] += arr[i] / 2;
        arr[i] %= 2;
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        assert(arr[i] == 0 || arr[i] == 1);
        count += arr[i];
    }
    cout << (count <= 2 ? "Y" : "N") << endl;
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
    // cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}

// 5 10 4 -1 10 20 30 20 2 3 -1
// 0 1  0  0 0  0  1  0  0 0  0
// 1 0  0  0 0  0  0  1  1 0  0
// 0 0  1  1 1  0  0  0  0 0  1
