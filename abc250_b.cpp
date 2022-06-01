#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
// const int N = 1e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
// int aaa[N], bbb[N], ddd[N], tak[N];
 
void run()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a; j++)
        {
            char c = i & 1 ? '#' : '.';
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < b; l++)
                {
                    printf("%c", c);
                }
                c = c == '.' ? '#' : '.';
            }
            printf("\n");
        }
    }
}
 
int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}