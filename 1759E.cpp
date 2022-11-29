#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

int solve(int n, ll h, int sz, int a_2, int a_3)
{
    if (n == sz)
    {
        return 0;
    }
    if (h > arr[n])
    {
        return 1 + solve(n + 1, h + arr[n] / 2, sz, a_2, a_3);
    }
    int c1 = a_2 ? solve(n, h * 2, sz, a_2 - 1, a_3) : 0,
        c2 = a_3 ? solve(n, h * 3, sz, a_2, a_3 - 1) : 0;
    return max(c1, c2);
}

void run()
{
    int n, h;
    scanf("%d%d", &n, &h);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    printf("%d\n", solve(0, h, n, 2, 1));
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}