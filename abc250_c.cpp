#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int nxt[N], prv[N], arr[N], idx[N];

void run()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i <= n + 1; i++)
    {
        nxt[i] = i + 1;
        prv[i] = i - 1;
    }
    while (q--)
    {
        int x;
        scanf("%d", &x);
        if (nxt[x] == n + 1)
        {
            x = prv[x];
        }
        // z -> x -> y -> w
        int y = nxt[x], z = prv[x], w = nxt[y];
        nxt[z] = y;
        nxt[y] = x;
        nxt[x] = w;
        prv[w] = x;
        prv[x] = y;
        prv[y] = z;
        // z -> y -> x -> w
    }
    for (int i = nxt[0]; i <= n; i = nxt[i])
    {
        printf("%d%c", i, " \n"[nxt[i] == n + 1]);
    }
}

// void run()
// {
//     int n, q;
//     scanf("%d%d", &n, &q);
//     for (int i = 1; i <= n; i++)
//     {
//         arr[i] = idx[i] = i;
//     }
//     while (q--)
//     {
//         int x;
//         scanf("%d", &x);
//         if (idx[x] == n)
//         {
//             x = arr[idx[x] - 1];
//         }
//         swap(arr[idx[x]], arr[idx[x] + 1]);
//         swap(idx[arr[idx[x]]], idx[arr[idx[x] + 1]]);
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         printf("%d%c", arr[i], " \n"[i == n]);
//     }
// }

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