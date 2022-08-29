#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], wor[N];
int n, m;
bool ok(int v)
{
    // cout << "----- " << v << " ";
    memset(wor, 0, sizeof(wor[0]) * (n + 1));
    for (int i = 0; i < m; i++)
    {
        if (wor[arr[i]] < v)
        {
            wor[arr[i]] += 1;
        }
        else
        {
            arr[i] *= -1;
        }
    }
    for (int i = 0, j = 1; i < m; i++)
    {
        if (arr[i] > 0)
        {
            continue;
        }
        arr[i] *= -1;
        while (j <= n && wor[j] >= v - 1)
        {
            j += 1;
        }
        if (j == n + 1)
        {
            for (i++; i < m; i++)
            {
                arr[i] = abs(arr[i]);
            }
            // cout << "0\n";
            return false;
        }
        wor[j] += 2;
    }
    // cout << "1\n";
    return true;
}

void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", arr + i);
    }
    int l = 1, h = (m + n - 1) / n * 2;
    while (l < h)
    {
        int v = (h - l) / 2 + l;
        if (ok(v))
        {
            h = v;
        }
        else
        {
            l = v + 1;
        }
    }

    printf("%d\n", h);
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