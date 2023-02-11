#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 3, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

int inp[N][N];

// bool work(int i, int j, int n)
// {
//     for (int ii = i; ii < n; ii++)
//     {
//         for (int jj = j - ii; jj >= 0; jj--)
//         {
//             if (inp[ii][jj] == 2)
//             {
//                 return false;
//             }
//             inp[ii][jj] = 1;
//         }
//     }
//     return true;
// }

bool ok(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inp[i][0] == 2)
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (int j = 0; j < n - i; j++)
        {
            if (inp[i][j] == 1)
            {
                if (!ok)
                {
                    return false;
                }
            }
            if (inp[i][j] == 2)
            {
                ok = false;
                if (inp[i][j - 1] == 1 && inp[i + 1][j - 1] == 1)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            scanf("%d", (int *)(inp + i) + j);
        }
    }
    if (ok(n))
    {
        ll ans = 0;
        for (int i = n - 1; ~i; i--)
        {
            if (inp[i][0] == 2)
            {
                ans = ans * 2;
            }
        }
    }
    else
    {
        printf("0\n");
    }
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}