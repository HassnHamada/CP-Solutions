#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e1 + 10, M = 1 << 11, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int ans = 0;
    for (int i = n - 2; ~i && ~ans; i--)
    {
        while (arr[i] >= arr[i + 1])
        {
            if (arr[i + 1] == 0)
            {
                ans = -1;
                break;
            }
            arr[i] /= 2;
            ans += 1;
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
