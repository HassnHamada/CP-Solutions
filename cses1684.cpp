#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 1e5 + 10;
int n, m, usd[N];
pair<int, int> inp[N];

bool sadCat(int i);
bool happyCat(int i);

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
    else
    {
        usd[v] = p;
        if (sadCat(i - 1))
        {
            return true;
        }
        usd[v] = 0;
    }
    return false;
}

bool sadCat(int i = n - 1)
{
    return i < 0 || happyCat(i, inp[i].first) || happyCat(i, inp[i].second);
}

void getInp()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        char a, c;
        int b, d;
        cin >> a >> b >> c >> d;
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
            cout << (usd[i] == 1 ? "+" : "-") << " \n"[i == m];
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(6) << fixed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}