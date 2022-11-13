#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e1 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

char mat[N][N];

void run()
{
    for (int i = 0; i < 8; i++)
    {
        scanf("%s", (char *)(mat + i));
    }
    printf(any_of(mat, mat + 8, [](char *ptr)
                  { return count(ptr, ptr + 8, 'R') == 8; })
               ? "R\n"
               : "B\n");
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
