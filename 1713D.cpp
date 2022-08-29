#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, L = 4, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];



void run()
{
    int n;
    scanf("%d", &n);
    n = 1 << n;
    iota(arr, arr + n, 1);
    while (n >= 4)
    {
        assert(n % 4 == 0);
        n /= 4;
        for (int i = 0, r; i < n; i++)
        {
            std::printf("? %d %d\n", arr[4 * i], arr[4 * i + 2]);
            std::fflush(stdout);
            scanf("%d", &r);
            if (r == 0)
            {
                std::printf("? %d %d\n", arr[4 * i + 1], arr[4 * i + 3]);
                std::fflush(stdout);
                scanf("%d", &r);
                if (r == 1)
                {
                    arr[i] = arr[4 * i + 1];
                }
                else if (r == 2)
                {
                    arr[i] = arr[4 * i + 3];
                }
                else
                {
                    exit(0);
                }
            }
            else if (r == 1)
            {
                std::printf("? %d %d\n", arr[4 * i], arr[4 * i + 3]);
                std::fflush(stdout);
                scanf("%d", &r);
                if (r == 1)
                {
                    arr[i] = arr[4 * i];
                }
                else if (r == 2)
                {
                    arr[i] = arr[4 * i + 3];
                }
                else
                {
                    exit(0);
                }
            }
            else if (r == 2)
            {
                std::printf("? %d %d\n", arr[4 * i + 1], arr[4 * i + 2]);
                std::fflush(stdout);
                scanf("%d", &r);
                if (r == 1)
                {
                    arr[i] = arr[4 * i + 1];
                }
                else if (r == 2)
                {
                    arr[i] = arr[4 * i + 2];
                }
                else
                {
                    exit(0);
                }
            }
            else
            {
                exit(1);
            }
        }
    }
    assert(n == 1 || n == 2);
    if (n == 2)
    {
        std::printf("? %d %d\n", arr[0], arr[1]);
        std::fflush(stdout);
        int r;
        scanf("%d", &r);
        if (r == 1)
        {
            // pass
        }
        else if (r == 2)
        {
            arr[0] = arr[1];
        }
        else
        {
            exit(0);
        }
    }
    std::printf("! %d\n", arr[0]);
    std::fflush(stdout);
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
