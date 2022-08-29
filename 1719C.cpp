#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 1e6 + 10, L = 1e6 + 10, Q = 448, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
int win[N];

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    memset(win, 0, sizeof(win[0]) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 1, j = 0; i < n; i++)
    {
        if (arr[i] > arr[j])
        {
            j = i;
        }
        win[j] += 1;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << win[i] << " ";
    // }
    // cout << endl;
    int mx = max_element(arr, arr + n) - arr;
    while (q--)
    {
        int i, k;
        scanf("%d%d", &i, &k);
        if (i - 1 == mx)
        {
            printf("%d\n", max(k - max(i - 2, 0), 0));
        }
        else
        {
            printf("%d\n", min(max(k - max(i - 2, 0), 0), win[i - 1]));
        }
    }
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
