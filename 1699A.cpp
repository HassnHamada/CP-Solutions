#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e3 + 20, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    if (n & 1)
    {
        printf("-1\n");
    }
    else
    {
        printf("0 0 %d\n", n / 2);
    }
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