#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5 + 10, M = 3e5, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

bool ok(int n)
{
    vector<int> tem(n + 1);
    tem[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        tem[i] = lcm(arr[i - 1], arr[i]);
    }
    tem[n] = arr[n - 1];
    for (int i = 0; i < n; i++)
    {
        if (gcd(tem[i], tem[i + 1]) != arr[i])
        {
            return false;
        }
    }
    return true;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    printf(ok(n) ? "YES\n" : "NO\n");
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