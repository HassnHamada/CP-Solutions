#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];

int solve(int &ii)
{
    // cout << "In " << ii << endl;
    int ret = 1, s = 0;
    for (; str[ii]; ii++)
    {
        // cout << ret << " " << s << " " << ii << endl;
        if (s)
        {
            if (str[ii] == ')')
            {
                assert(s == 1);
                s -= 1;
            }
            else
            {
                ret += solve(ii);
                ii -= 1;
            }
        }
        else
        {
            if (str[ii] == ')')
            {
                break;
            }
            assert(s == 0);
            s += 1;
        }
    }
    // cout << "Out " << ii << " " << ret << endl;
    return ret;
}

void run()
{
    int n;
    scanf("%d%s", &n, str);
    int ans = 0;
    for (int i = 0; str[i];)
    {
        ans += solve(i);
    }
    printf("%d\n", ans);
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