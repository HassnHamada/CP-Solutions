#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N];
char ans[N];

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int cq = 0;
    for (int i = n - 1; ~i; i--)
    {
        if (arr[i] <= cq)
        {
            ans[i] = '1';
        }
        else if (cq < q)
        {
            cq++;
            ans[i] = '1';
        }
        else
        {
            ans[i] = '0';
        }
    }
    ans[n] = '\0';
    printf("%s\n", ans);
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