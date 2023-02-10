#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 1e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;



void run()
{
    int n = 0;
    scanf("%d", &n);
    set<int> sss;
    if (n & 1)
    {
        printf("Yes\n");
        int tar = (n + 1) / 2 * 3;
        for (int i = 1; i <= n; i += 2, tar++)
        {
            printf("%d %d\n", i, tar - i);
            assert(sss.find(i) == sss.end());
            assert(sss.find(tar - i) == sss.end());
            sss.insert(i);
            sss.insert(tar - i);
        }
        for (int i = 2; i < n; i += 2, tar++)
        {
            printf("%d %d\n", i, tar - i);
            assert(sss.find(i) == sss.end());
            assert(sss.find(tar - i) == sss.end());
            sss.insert(i);
            sss.insert(tar - i);
        }
    }
    else
    {
        printf("No\n");
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

// r l l l
// 1 3 5 11 15
// 1 3 5 11 15
// r l l r l
//  2 2 6  4