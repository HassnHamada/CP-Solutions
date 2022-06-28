#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e4 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
// int aaa[N], bbb[N], ccc[N];

void run()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("9\n");
    }
    else if (n == 2)
    {
        printf("98\n");
    }
    else if (n == 3)
    {
        printf("989\n");
    }
    else
    {
        printf("989");
        for (int i = 0; i < n - 3; i++)
        {
            printf("%d", i % 10);
        }
        printf("\n");
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d"/, &n), n)
    {
        run();
    }

    return 0;
}
