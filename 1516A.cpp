#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; k && i < n - 1; i++)
    {
        int j = min(k, arr[i]);
        k -= j;
        arr[i] -= j;
        arr[n - 1] += j;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d%c", arr[i], " \n"[i + 1 == n]);
    }
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