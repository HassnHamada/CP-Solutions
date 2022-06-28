#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 30, MOD = 1e9 + 7, HV = 151;
int arr[N];

void run()
{
    int n, z = 0, pve = 0, nve = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int j = pve + nve;
        scanf("%d", arr + j);
        z += arr[j] == 0;
        pve += arr[j] > 0;
        nve += arr[j] < 0;
    }
    bool ok;
    if (z == n)
    {
        ok = true;
    }
    else if (pve >= 3 || nve >= 3)
    {
        ok = false;
    }
    else
    {
        int m = pve + nve;
        assert(m <= 4);
        if (z)
        {
            arr[m++] = 0;
        }
        // cout << m << endl;
        sort(arr, arr + m);
        ok = true;
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                for (int k = j + 1; k < m; k++)
                {
                    int v = arr[i] + arr[j] + arr[k];
                    // cout << v << endl;
                    int *ptr = lower_bound(arr, arr + m, v);
                    // if (ptr == arr + m)
                    // {
                    //     cout << "out\n";
                    // }
                    // else
                    // {
                    //     cout << *ptr << endl;
                    // }
                    if (ptr == arr + m || (*ptr) != v)
                    {
                        // cout << "Dasd\n";
                        ok = false;
                    }
                }
            }
        }
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