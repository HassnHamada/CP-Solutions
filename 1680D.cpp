#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 448, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n, k, z = 0;
    scanf("%d%d", &n, &k);
    ll tot = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        tot += arr[i];
        z += arr[i] == 0;
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}