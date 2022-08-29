#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int n;
char aaa[N], bbb[N];

// int dfs(int cn = 0, int p = 0)
// {
//     cout << "in " << cn << " " << p << endl;
//     if (cn == n)
//     {
//         cout << "out " << cn << " " << p << endl;
//         return p >> 1 ? -1 : 0;
//     }
//     int t = bbb[cn] - '0',
//         c = (aaa[cn] - '0') ^ (p & 1);
//     int ret = cn == 0 || ((p >> 1) == (c ^ t)) ? dfs(cn + 1, p) : -1;
//     if (ret == -1 || (ret & 1) != (c ^ t))
//     {
//         if (c)
//         {
//             ret = cn == 0 || ((p >> 1) != (c ^ t)) ? dfs(cn + 1, ((p & 1) ^ 1) | ((c ^ t) << 1)) : -1;
//             // cout << ret << endl;
//             if (ret == -1 || (ret & 1) != (c ^ t))
//             {
//                 ret = -1;
//             }
//             else
//             {
//                 ret += 1;
//             }
//         }
//         else
//         {
//             ret = -1;
//         }
//     }
//     cout << "out " << cn << " " << p << " " << ret << endl;
//     return ret;
// }

int dfs2(int cn, int p)
{
    cout << "in " << cn << " " << p << endl;
    if (cn == n)
    {
        cout << "out " << cn << " " << p << endl;
        return 0;
    }
    int t = bbb[cn] - '0',
        c = (aaa[cn] - '0') ^ p;
    int ret;
    if (c ^ t)
    {
    }
    else
    {
    }
    cout << "out " << cn << " " << p << " " << ret << endl;
    return ret;
}

void run()
{
    scanf("%d", &n);
    scanf("%s", aaa);
    scanf("%s", bbb);
    // char *it = find(aaa, aaa + n, '1');
    // if (it != aaa + n)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (aaa + i == it)
    //         {
    //             continue;
    //         }
    //         aaa[i] = aaa[i] == '0' ? '1' : '0';
    //     }
    // }
    // printf("%s\n", aaa);
    // printf("%d\n", dfs());
    printf("%d\n", dfs2(0, 0));
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}