#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, M = 3, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char inp[N];

void run()
{
    int n;
    scanf("%d", &n);
    scanf("%s", inp);
    for (int i = 0; i < n / 2; i++)
    {
        inp[i] = inp[i] != inp[n - i - 1];
    }
    n = unique(inp, inp + n / 2) - inp;
    printf(count(inp, inp + n, 1) <= 1 ? "Yes\n" : "No\n");
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}