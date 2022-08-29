#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 26, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, p = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        p += i && arr[i] == arr[i - 1];
    }
    int ans = 0;
    for (int i = n - 2; p > 1 && i; i--)
    {
        if (arr[i] == arr[i + 1])
        {
            int v = 1;
            if (arr[i + 1] == v || (i > 1 && arr[i - 2] == v))
            {
                v = 2;
            }
            if (arr[i + 1] == v || (i > 1 && arr[i - 2] == v))
            {
                v = 3;
            }
            assert(arr[i + 1] != v && (i == 1 || arr[i - 2] != v));
            p -= (i > 1 && arr[i - 1] == arr[i - 2] ? 1 : 0) + (arr[i] == arr[i - 1] ? 1 : 0);
            arr[i - 1] = arr[i] = v;
            ans += 1;
            // cout << i << " " << p << endl;
            // for (int j = 0; j < n; j++)
            // {
            //     cout << arr[j] << " ";
            // }
            // cout << endl;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}