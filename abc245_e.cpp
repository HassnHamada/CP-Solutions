#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;

struct Node
{
    int x, y, p;
    bool operator<(Node &other)
    {
        return this->x == other.x ? this->p < other.p : this->x < other.x;
    }
} arr[N];

void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].x);
        arr[i].p = 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].y);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr[n + i].x);
        arr[n + i].p = 1;
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr[n + i].y);
    }
    sort(arr, arr + n + m);
    map<int, int> mmm;
    for (int i = n + m - 1; ~i; i--)
    {
        if (arr[i].p)
        {
            mmm[arr[i].y]++;
        }
        else
        {
            map<int, int>::iterator it = mmm.lower_bound(arr[i].y);
            if (it == mmm.end())
            {
                printf("No\n");
                return;
            }
            if (--(it->second) == 0)
            {
                mmm.erase(it);
            }
        }
    }
    printf("Yes\n");
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