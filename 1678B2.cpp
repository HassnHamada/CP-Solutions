#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n, ans = 0, l = -1, s = 0;
    scanf("%d\r\n", &n);
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf("%c", &c);
        arr[i] = c == '1';
    }
    for (int i = 0; i < n; i += 2)
    {
        arr[i / 2] = arr[i] == arr[i + 1] ? arr[i] : 2;
    }
    n /= 2;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 2)
        {
            ans += 1;
        }
        else
        {
            if (l != arr[i])
            {
                s += 1;
            }
            l = arr[i];
        }
    }
    printf("%d %d\n", ans, max(s, 1));
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