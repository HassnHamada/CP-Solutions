#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 5e1 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int arr[N];

void run()
{
    int n, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        s += arr[i];
    }
    if (s & 1)
    {
        int ans = INF;
        for (int i = 0; i < n; i++)
        {
            int t = 0, v = arr[i];
            while ((arr[i] & 1) == (v & 1))
            {
                t++;
                v /= 2;
            }
            ans = std::min(ans, t);
        }
        printf("%d\n", ans);
    }
    else
    {
        printf("0\n");
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