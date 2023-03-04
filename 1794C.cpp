#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, M = 21, L = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        while (arr[j] < (i - j + 1))
        {
            j++;
        }
        printf("%d%c", i - j + 1, " \n"[i + 1 == n]);
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}