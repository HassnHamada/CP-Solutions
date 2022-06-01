#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n, ans = 0;
    scanf("%d\r\n", &n);
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf("%c", &c);
        arr[i] = c == '1';
    }
    for (int i = 0; i < n; i += 2)
    {
        ans += arr[i] != arr[i + 1];
    }
    printf("%d\n", ans);
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