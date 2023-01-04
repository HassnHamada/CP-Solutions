#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

// char inp[N];

void run()
{
    int n;
    scanf("%d", &n);
    pair<int, int> ans = {-1, -1};
    if (n & 1)
    {
        for (int i = -N; ans.first == -1 && i < 0; i++)
        {
            // j == (1 - n / 2 ) * i / ((n + 1) / 2 - 1)
            if ((1 - n / 2) * i % ((n + 1) / 2 - 1) == 0)
            {
                int j = (1 - n / 2) * i / ((n + 1) / 2 - 1);
                if (j && j <= N)
                {
                    ans = {j, i};
                }
            }
            // j == (1 - (n + 1) / 2) * i / (n / 2 - 1)
            else if ((1 - (n + 1) / 2) * i % (n / 2 - 1) == 0)
            {
                int j = (1 - (n + 1) / 2) * i / (n / 2 - 1);
                if (j && j <= N)
                {
                    ans = {i, j};
                }
            }
        }
        if (ans.first == -1)
        {
            printf("NO\n");
            return;
        }
    }
    else
    {
        ans = {1, -1};
    }
    int tot = 0;
    printf("YES\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", i & 1 ? ans.second : ans.first, " \n"[i + 1 == n]);
        tot += i & 1 ? ans.second : ans.first;
    }
    // if (tot != ans.first + ans.second)
    // {
    //     cout << n << " " << tot << " " << ans.first + ans.second << endl;
    // }
    assert(tot == ans.first + ans.second);
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