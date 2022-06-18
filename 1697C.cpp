#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int n, acc[M][N];
char sss[N], ttt[N];

// TODO
void run()
{
    scanf("%d%s%s", &n, sss, ttt);
    bool ok = count(sss, sss + n, 'b') == count(sss, sss + n, 'b');
    for (int i = 0, j = 0; ok && i < n; i++)
    {
        if (sss[i] == 'b')
        {
            continue;
        }
        while (ttt[j] == 'b')
        {
            j += 1;
        }
        if (sss[i] != ttt[j])
        {
            /* code */
        }
        
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
