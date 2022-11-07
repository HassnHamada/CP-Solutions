#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 100, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
bool wat[N];

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", arr + i);
    }
    bool ok = true;
    for (int i = 0, j = k, e = n * m - 3; ok && i < k; i++)
    {
        while (wat[j])
        {
            j--;
            e++;
            continue;
        }
        if (arr[i] == j)
        {
            j--;
        }
        else
        {
            wat[arr[i]] = true;
            if (--e == 0)
            {
                ok = false;
            }
        }
    }
    memset(wat, 0, sizeof(wat[0]) * (k + 1));
    printf(ok ? "YA\n" : "TIDAK\n");
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
}#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 100, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
bool wat[N];

void run()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", arr + i);
    }
    bool ok = true;
    for (int i = 0, j = k, e = n * m - 3; ok && i < k; i++)
    {
        while (wat[j])
        {
            j--;
            e++;
            continue;
        }
        if (arr[i] == j)
        {
            j--;
        }
        else
        {
            wat[arr[i]] = true;
            if (--e == 0)
            {
                ok = false;
            }
        }
    }
    memset(wat, 0, sizeof(wat[0]) * (k + 1));
    printf(ok ? "YA\n" : "TIDAK\n");
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