#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int n, m, usd[N];
pair<int, int> inp[N];

bool sadCat(int i);

bool happyCat(int i, int v)
{
    int p = (v == abs(v) ? 1 : -1);
    v = abs(v);
    if (usd[v])
    {
        if (usd[v] == p)
        {
            return sadCat(i - 1);
        }
        return false;
    }
    usd[v] = p;
    if (sadCat(i - 1))
    {
        return true;
    }
    usd[v] = 0;
    return false;
}

bool sadCat(int i = n - 1)
{
    return i < 0 || happyCat(i, inp[i].first) || happyCat(i, inp[i].second);
}

void getInp()
{
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        char a, c;
        int b, d;
        scanf("%c%d %c%d\n", &a, &b, &c, &d);
        b *= (a == '+' ? 1 : -1);
        d *= (c == '+' ? 1 : -1);
        inp[i] = {b, d};
    }
}

void run()
{
    getInp();
    if (sadCat())
    {
        for (int i = 1; i <= m; i++)
        {
            printf("%c%c", "-+"[usd[i] == 1], " \n"[i == m]);
        }
    }
    else
    {
        printf("IMPOSSIBLE\n");
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