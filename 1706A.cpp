#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    string s;
    for (int i = 0; i < m; i++)
    {
        s.push_back('B');
    }
    for (int i = 0; i < n; i++)
    {
        int u = arr[i] - 1, v = m - arr[i];
        if (u > v)
        {
            swap(u, v);
        }
        if (s[u] == 'A')
        {
            s[v] = 'A';
        }
        else
        {
            s[u] = 'A';
        }
    }
    printf("%s\n", s.c_str());
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