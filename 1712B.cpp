#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 17, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = n; i > 1; i -= 2)
    {
        arr[i] = i - 1;
        arr[i - 1] = i;
    }
    if (n & 1)
    {
        arr[1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d%c", arr[i], " \n"[i == n]);
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
