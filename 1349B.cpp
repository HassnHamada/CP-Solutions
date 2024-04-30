#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> vec;
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        ok = ok || arr[i] == k;
        arr[i] = arr[i] == k ? 1 : arr[i] > k ? 2
                                              : 0;
    }
    if (ok)
    {
        ok = n == 1;
        for (int i = 0; !ok && i < n; i++)
        {
            for (int j = i + 1; !ok && j < n && j - i <= 2; j++)
            {
                ok = arr[i] && arr[j];
            }
        }
    }

    printf(ok ? "yes\n" : "no\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}