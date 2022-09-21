#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

const int N = 1e5 + 10, M = 2, L = 4, MOD = 9, HV = 151, INF = 0x3f3f3f3f;

int arr[M][N];

// (e - 1) + o || (o - 1) + e
void run()
{
    int n, o = 0, e = 0;
    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        arr[v & 1][v & 1 ? o++ : e++] = i + 1;
    }
    printf("%d\n", n - 1);
    if (e && arr[0][0] == 1)
    {
        while (--e)
        {
            printf("%d %d\n", arr[0][e - 1], arr[0][e]);
        }
        while (o--)
        {
            printf("1 %d\n", arr[1][o]);
        }
    }
    else if (o && arr[1][0] == 1)
    {
        while (--o)
        {
            printf("%d %d\n", arr[1][o - 1], arr[1][o]);
        }
        while (e--)
        {
            printf("1 %d\n", arr[0][e]);
        }
    }
    else
    {
        assert(false);
    }
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