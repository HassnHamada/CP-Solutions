#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int m, ans = 0;
    scanf("%d", &m);
    for (int i = 0, v; i < m; i++)
    {
        scanf("%d", &v);
        ans = (ans + v) % n;
    }
    printf("%d\n", arr[ans]);
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