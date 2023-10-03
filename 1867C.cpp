#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <set>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
int arr[N];

void run()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        ans += ans == v;
    }
    while (true)
    {
        printf("%d\n", ans);
        fflush(stdout);
        scanf("%d", &ans);
        if (ans == -1)
        {
            break;
        }
        else if (ans == -2)
        {
            exit(1);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}