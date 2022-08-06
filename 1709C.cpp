#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char str[N];

bool calc()
{
    int c = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
        {
            c += 1;
        }
        else
        {
            c -= 1;
        }
        if (c < 0)
        {
            return false;
        }
    }
    return c == 0;
}

void run()
{

    scanf("%s", str);
    int n = strlen(str);
    assert(n % 2 == 0);
    vector<int> q;
    int op = n / 2, cl = n / 2;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            op -= 1;
        }
        else if (str[i] == ')')
        {
            cl -= 1;
        }
        else
        {
            q.push_back(i);
        }
    }

    for (int i = 0; i < (int)q.size(); i++)
    {
        if (i < op)
        {
            str[q[i]] = '(';
        }
        else
        {
            str[q[i]] = ')';
        }
    }
    bool ok = true;
    if (op && cl)
    {
        swap(str[q[op]], str[q[op - 1]]);
        ok = !calc();
    }
    printf(ok ? "YES\n" : "NO\n");
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
