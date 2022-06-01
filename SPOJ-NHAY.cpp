#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, MOD = 1e9 + 7;
// char pat[N], str[N];
// int f[N];
char *pat;
int *f;

int newL(int l, char c)
{
    while (l && c != pat[l])
    {
        l = f[l - 1];
    }
    return l += (int)(c == pat[l]);
}

void computeF()
{
    if (!pat[0])
    {
        return;
    }
    f[0] = 0;
    for (int i = 1; pat[i]; i++)
    {
        f[i] = newL(f[i - 1], pat[i]);
    }
}

vector<int> match()
{
    computeF();
    // for (int i = 0; i < pat[i]; i++)
    // {
    //     printf("%d ", f[i]);
    // }
    // printf("\n");
    vector<int> res;
    int l = 0;
    char c = '\0';
    for (int i = 0; true; i++)
    {
        scanf("%c", &c);
        // cout << c << endl;
        if (c == '\n')
        {
            break;
        }
        l = newL(l, c);
        // cout << i << " " << l << endl;
        if (!pat[l])
        {
            res.push_back(i - l + 1);
        }
        // res.push_back(i - l + 1);
    }
    return res;
}

void run()
{
    scanf("%s\n", pat);
    // printf("%s\n", pat);
    auto res = match();
    // cout << res.size() << endl;
    for (auto &&i : res)
    {
        printf("%d\n", i);
    }
    printf("\n");
}
int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    // strcpy(pat, "aab");
    // scanf("%s%s", pat, str);
    // computeF();
    // for (int i = 0; i < pat[i]; i++)
    // {
    //     printf("%d ", f[i]);
    // }
    // printf("\n");
    // auto res = match();
    // for (auto &&i : res)
    // {
    //     printf("%d ", i);
    // }

    // printf("\n");
    int t;
    // scanf("%d", &t);
    while (~scanf("%d", &t))
    {
        pat = (char *)malloc((t + 1) * sizeof(char));
        f = (int *)malloc(t * sizeof(int));
        run();
        free(pat);
        free(f);
    }

    return 0;
}