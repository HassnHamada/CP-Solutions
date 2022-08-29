#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 15e4 + 10, M = 6, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    n = unique(arr, arr + n) - arr;
    printf("%d\n", (int)count_if(arr, arr + n, [&x, &y](int i)
                                 { return i > x && i < y; }));
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