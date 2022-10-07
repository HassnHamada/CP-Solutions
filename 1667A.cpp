#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    arr[0] = -1;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int v = arr[i - 1] / arr[i] + 1;
        arr[i] = v * arr[i];
        // cout << v << endl;
        ans += v;
    }
    // assert(arr[0] == 0);
    for (int i = 1; i < n; i++)
    {
        assert(arr[i] > arr[i - 1]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    printf("%d\n", ans);
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
