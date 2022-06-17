#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
char str[N];
int zzz[N], fff[N];

void computeZ()
{
    int &i = zzz[0];
    int s = 0, e = 0;
    for (i = 1; str[i]; i++)
    {
        if (i >= e)
        {
            s = e = i;
            zzz[i] = 0;
        }
        else
        {
            zzz[i] = zzz[i - s];
        }
        if (i + zzz[i] >= e)
        {
            s = i;
            while (str[e] == str[e - s])
            {
                e++;
            }
            zzz[i] = e - s;
        }
    }
}

int newL(int i, char ch)
{
    while (i && str[i] != ch)
    {
        i = fff[i - 1];
    }
    return i + (int)(str[i] == ch);
}

void computeF()
{
    int n = strlen(str);
    for (int i = 1; i < n; i++)
    {
        fff[i] = newL(fff[i - 1], str[i]);
    }
}

void run()
{
    while (true)
    {
        int k;
        scanf("%d%s", &k, str);
        if (k == -1)
        {
            break;
        }
        int n = strlen(str);
        if (k < n)
        {
            printf("0\n");
            continue;
        }
        // computeZ();
        computeF();
        printf("%d\n", (k - n) / (n - fff[n - 1]) + 1);
    }
}

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