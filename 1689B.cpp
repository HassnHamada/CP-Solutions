#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 32, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
int n, arr[N];
bool usd[N];

bool ans(vector<int> &out)
{
    if ((int)(out.size()) == n)
    {
        return true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (usd[i] || arr[out.size()] == i)
        {
            continue;
        }
        out.push_back(i);
        usd[i] = true;
        if (ans(out))
        {
            return true;
        }
        out.pop_back();
        usd[i] = false;
    }
    return false;
}

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    memset(usd, 0, sizeof(usd[0]) * (n + 1));
    vector<int> out;
    if (ans(out))
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d%c", out[i], " \n"[i == n - 1]);
        }
    }
    else
    {
        printf("-1\n");
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d"/, &n), n)
    {
        run();
    }

    return 0;
}
