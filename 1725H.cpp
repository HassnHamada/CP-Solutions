#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], frq[M];
char ans[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        frq[arr[i] %= M] += 1;
    }
    if (frq[0] > n / 2)
    {
        printf("2\n");
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                ans[i] = '0';
            }
        }
        for (int i = 0, j = n / 2 - frq[1] - frq[2]; i < n; i++)
        {
            if (arr[i] == 0)
            {
                ans[i] = j-- > 0 ? '0' : '1';
            }
        }
    }
    else
    {
        printf("0\n");
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                ans[i] = '0';
            }
        }
        for (int i = 0, j = n / 2 - frq[0]; j; i++)
        {
            assert(i < n);
            if (arr[i] != 0)
            {
                ans[i] = '0';
                j--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == 0)
            {
                ans[i] = '1';
            }
        }
    }
    ans[n] = '\0';
    assert(count(ans, ans + n, '0') == count(ans, ans + n, '1'));
    printf("%s\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}