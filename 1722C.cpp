#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e3 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N][M];

map<string, int> mmm;

int my_count(void *ptr, int sz)
{
    int ret = 0;
    for (int i = 0; i < sz; i++)
    {
        int v = mmm[(char *)(ptr) + i * M];
        if (v == 1)
        {
            ret += 3;
        }
        else if (v == 2)
        {
            ret += 1;
        }
        else if (v == 3)
        {
            // ret += 0;
        }
        else
        {
            assert(false);
        }
    }
    return ret;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s", (char *)(str + N / 3 * j + i));
            mmm[str[N / 3 * j + i]]++;
        }
    }
    printf("%d %d %d\n", my_count(str, n), my_count(str + N / 3 * 1, n), my_count(str + N / 3 * 2, n));
    mmm.clear();
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