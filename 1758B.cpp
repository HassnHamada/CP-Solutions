#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 128, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    int n;
    scanf("%d", &n);
    if (n & 1)
    {
        int xor_ = 0, sum_ = 0;
        for (int i = 0; i < n; i++)
        {
            printf("1%c", " \n"[i + 1 == n]);
            xor_ ^= 1;
            sum_ += 1;
        }
        // assert(sum_ % n == 0);
        // assert(sum_ / n == xor_);
    }
    else
    {
        int xor_ = 0, sum_ = 0;
        for (int i = 0; i < n - 2; i++)
        {
            printf("2 ");
            xor_ ^= 2;
            sum_ += 2;
        }
        printf("1 ");
        xor_ ^= 1;
        sum_ += 1;
        printf("3\n");
        xor_ ^= 3;
        sum_ += 3;
        // assert(sum_ % n == 0);
        // assert(sum_ / n == xor_);
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}