#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char inp[M][N];
std::map<std::tuple<int, int, int>, bool> dp;

bool ok(int i, int j, int p, int n)
{
    std::tuple<int, int, int> k = {i, j, p};
    assert(inp[i][j] == 'B');
    inp[i][j] = 'W';
    if (dp.find(k) == dp.end())
    {
        if (inp[i ^ 1][j] == 'B')
        {
            dp[k] = ok(i ^ 1, j, 1, n);
        }
        else if (inp[i][j + 1] == 'B')
        {
            dp[k] = ok(i, j + 1, 0, n);
        }
        else
        {
            dp[k] = j == n - 1;
        }
    }
    inp[i][j] = 'B';
    return dp[k];
}

void run()
{
    int n;
    scanf("%d%s%s", &n, (char *)inp, (char *)(inp + 1));
    printf(((inp[0][0] == 'B' && ok(0, 0, 0, n)) ||
            (inp[1][0] == 'B' && ok(1, 0, 0, n)))
               ? "YES\n"
               : "NO\n");
    dp.clear();
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