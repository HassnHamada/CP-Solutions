#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long ll;

void qw(int n)
{
    printf("? %d\n", n);
    fflush(stdout);
}

void qa(int n)
{
    printf("! %d\n", n);
    fflush(stdout);
}

int qr()
{
    int r;
    scanf("%d", &r);
    if (r == -1)
    {
        exit(1);
    }
    return r;
}

void run()
{
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1;; i += (i + k <= n - k + 1 ? k : n % k / 2))
    {
        qw(i);
        ans ^= qr();
        if (i == n - k + 1)
        {
            break;
        }
    }
    qa(ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}