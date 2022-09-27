#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N], ans[N];
int ins[M], frq[M];

void run()
{
    memset(frq, 0, sizeof(frq));
    memset(ins, -1, sizeof(ins));
    scanf("%s", str);
    int n = strlen(str), m = 0;
    for (int i = n - 1, j = M - 1; ~i; i--)
    {
        if (str[i] - '0' < j)
        {
            // cout << str[i] << endl;
            ins[j--] = ++i;
            if (j == 0)
            {
                break;
            }
        }
    }
    // for (int i = 0; i < M; i++)
    // {
    //     cout << ins[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n;)
    {
        bool ok = true;
        for (int j = 1; j < M; j++)
        {
            if (frq[j] == 0)
            {
                continue;
            }
            assert(ins[j] != -1);
            if (ins[j] == i)
            {
                ans[m++] = j + '0';
                frq[j] -= 1;
                ok = false;
                break;
            }
        }
        if (ok)
        {
            ans[m++] = str[i++];
        }
        while (m >= 2 && ans[m - 1] < ans[m - 2])
        {
            frq[min(ans[m - 2] - '0' + 1, 9)]++;
            // cout << min(ans[m - 2] - '0' + 1, 9) << " " << frq[min(ans[m - 2] - '0' + 1, 9)] << endl;
            ans[m - 2] = ans[m - 1];
            m -= 1;
        }
    }
    for (int j = 1; j < M; j++)
    {
        if (frq[j] == 0)
        {
            continue;
        }
        // assert(ins[j] == n);
        while (frq[j] != 0)
        {
            ans[m++] = j + '0';
            frq[j] -= 1;
        }
    }
    assert(m == n);
    // for (int i = 0; i < M; i++)
    // {
    //     assert(frq[i] == 0);
    // }
    ans[m] = '\0';
    printf("%s\n", ans);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}