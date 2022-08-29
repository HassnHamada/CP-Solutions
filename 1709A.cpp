#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e1 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int x;
    scanf("%d", &x);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", arr + i + 1);
    }
    int o = 0;
    while (x)
    {
        x = arr[x];
        o += 1;
    }
    printf(o == 3 ? "YES\n" : "NO\n");
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