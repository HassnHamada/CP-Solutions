#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];
int zzz[N], n;

void computeZ()
{
    int &i = zzz[0];
    int l = 0, r = 0;
    for (i = 1; str[i]; i++)
    {
        if (i >= r)
        {
            l = r = i;
            zzz[i] = 0;
        }
        else
        {
            zzz[i] = zzz[i - l];
        }
        if (i + zzz[i] >= r)
        {
            l = i;
            while (str[r] == str[r - l])
            {
                r++;
            }
            zzz[i] = r - l;
        }
    }
}

bool ok(int ii)
{
    for (int i = ii; i < n; i += ii)
    {
        if (zzz[i] < min(ii, n - i))
        {
            return false;
        }
    }
    return true;
}

void run()
{
    scanf("%s", str);
    n = strlen(str);
    computeZ();
    for (int i = 1; i <= n; i++)
    {
        if (ok(i))
        {
            printf("%d ", i);
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