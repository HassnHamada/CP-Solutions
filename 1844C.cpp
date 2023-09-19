#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

ll arr[N];

ll calc(vector<ll> &&vec)
{
    for (int i = 0; i < (int)vec.size(); i++)
    {
        calc(vector<ll>(vector<ll>(vec.begin(), vec.begin() + i),
                        vector<ll>(vec.begin() + i + 1, vec.end())))
    }
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", arr + i);
    }
    cout << calc(vector<ll>(arr, arr + n)) << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d%c", ans[i], " \n"[i + 1 == n]);
    // }
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
