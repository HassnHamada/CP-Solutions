#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int n, arr[N];

void run()
{
    int n, mx1 = INT32_MIN, mx2 = INT32_MIN;
    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        mx1 = max(mx1, v);
    }
    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        mx2 = max(mx2, v);
    }
    printf(mx1 >= mx2 ? "Alice\n" : "Bob\n");
    printf(mx2 >= mx1 ? "Bob\n" : "Alice\n");
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