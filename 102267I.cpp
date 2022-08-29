#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 17, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N], n;
char str[N];

int getnum(int &i)
{
    int ret = 0;
    for (; str[i]; i++)
    {
        if (str[i] == '(' || str[i] == ')')
        {
            break;
        }
        ret = ret * 10 + str[i] - '0';
    }
    return ret;
}

void run()
{
    scanf("%d\n%s", &n, str);
    stack<int> stk;
    for (int i = 0; str[i]; )
    {
        if (str[i] == ')')
        {
            stk.pop();
            i += 1;
        }
        else if (str[i] == '(')
        {
            i += 1;
        }
        else
        {
            int v = getnum(i);
            ans[v] = stk.empty() ? 0 : stk.top();
            stk.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d%c", ans[i], " \n"[i == n]);
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
