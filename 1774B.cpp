#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N];

void run()
{
    int n, m, k, mx = 0, c = 0;
    scanf("%d%d%d", &n, &m, &k);
    // std::cout << n << " " << m << " " << k << '\n';
    for (int i = 0, v; i < m; i++)
    {
        // scanf("%d", arr + i);
        scanf("%d", &v);
        mx = std::max(mx, v);
        c += v > n / k;
    }
    printf(c > n % k || mx > (n + k - 1) / k ? "NO\n" : "YES\n");
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