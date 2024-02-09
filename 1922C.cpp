#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include <stdio.h>
#endif
using namespace std;
typedef long long ll;

const int N = (int)(1e5 + 10);
int arr[N], frw[N], bcw[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, inc = 1;
        if (j && arr[j + 1] - arr[j] > arr[j] - arr[j - 1])
        {
            inc = arr[j + 1] - arr[j];
        }
        frw[i] = frw[i - 1] + inc;
    }
    for (int i = n - 2; ~i; i--)
    {
        int j = i + 1, inc = 1;
        if (j < n - 1 && arr[j + 1] - arr[j] < arr[j] - arr[j - 1])
        {
            inc = arr[j] - arr[j - 1];
        }
        bcw[i] = bcw[i + 1] + inc;
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int s, e;
        scanf("%d%d", &s, &e);
        int ans = s < e ? frw[e - 1] - frw[s - 1] : bcw[e - 1] - bcw[s - 1];
        printf("%d\n", ans);
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