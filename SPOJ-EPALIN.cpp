#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5 + 5;
char str[N];
int ppp[N];

void extend()
{
    int n = strlen(str);
    for (int i = (n + 1) * 2; i; i -= 2)
    {
        str[i] = str[n--];
        str[i - 1] = '#';
    }
    str[0] = '$';
}

void shrink()
{
    int i = 0;
    for (int j = 2; str[j]; j += 2)
    {
        str[i++] = str[j];
    }
    str[i] = '\0';
}

void manacher()
{
    int n = strlen(str), c = 1, r = 1;
    memset(ppp, 0, n * sizeof(ppp[0]));
    for (int i = 2; i < n; i++)
    {
        int m = 2 * c - i;
        if (i < r)
        {
            ppp[i] = min(ppp[m], r - i);
        }
        while (str[i + ppp[i] + 1] == str[i - ppp[i] - 1])
        {
            ppp[i]++;
        }
        if (i + ppp[i] > r)
        {
            c = i;
            r = i + ppp[i];
        }
    }
}

void run()
{
    extend();
    manacher();
    int n = strlen(str);
    int mx = 0, mxi = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + ppp[i] == n - 1)
        {
            mx = ppp[i];
            mxi = i;
        }
    }
    // cout << mx << " " << mxi << endl;
    // cout << str << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ppp[i] << " ";
    // }
    // cout << endl;

    for (int i = (n - 1); i; i--)
    {
        if (i <= mxi + mx && i >= mxi - mx)
        {
            continue;
        }
        str[n++] = str[i];
    }
    str[n] = '\0';
    // cout << str << endl;
    // n = strlen(str);
    // cout << str << endl;
    manacher();
    shrink();
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ppp[i] << " ";
    // }
    // cout << endl;
    // cout << *max_element(ppp, ppp + n) << endl;
    // cout << n << endl;
    assert(*max_element(ppp, ppp + n) == (int)strlen(str));
    // cout << str << endl;
    printf("%s\n", str);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    while (~scanf("%s", str))
    {
        run();
    }
    return 0;
}