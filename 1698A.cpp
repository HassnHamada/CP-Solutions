#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// const int N = 2e5 + 10, M = 30, MOD = 1e9 + 7, HV = 151;
// char str[N];
// map<string, int> drk;
// vector<string> sad;

// struct BIT
// {
//     int tre[N];
//     void add(int i, int v)
//     {
//         for (i++; i <= N; i += (i & (-i)))
//         {
//             tre[i - 1] += v;
//         }
//     }
//     int get(int i)
//     {
//         int ret = 0;
//         for (i++; i; i -= (i & (-i)))
//         {
//             ret += tre[i - 1];
//         }
//         return ret;
//     }
// } bit;

void run()
{
    int n, ans;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ans);
    }
    printf("%d\n", ans);
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