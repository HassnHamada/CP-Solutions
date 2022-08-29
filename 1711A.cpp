#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 64, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char arr[N][N];

void run()
{
    int n;
    scanf("%d", &n);
    printf("%d", n);
    for (int i = 1; i < n; i++)
    {
        printf(" %d", i);
        // assert(i % (i + 1));
    }
    printf("\n");
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