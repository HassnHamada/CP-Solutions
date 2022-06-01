#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 20, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int n, aaa[N], bbb[N];

void run()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", aaa + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", bbb + i);
    }
    vector<pair<int, int>> mov;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = {i, i};
        for (int j = i + 1; j < n; j++)
        {
            if (aaa[p.second] > aaa[j])
            {
                p.second = j;
            }
        }
        if (p.first == p.second)
        {
            continue;
        }
        swap(aaa[p.first], aaa[p.second]);
        swap(bbb[p.first], bbb[p.second]);
        mov.push_back(p);
    }
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = {i, i};
        for (int j = i + 1; j < n; j++)
        {
            if (bbb[p.second] > bbb[j])
            {
                p.second = j;
            }
        }
        if (p.first == p.second)
        {
            continue;
        }
        swap(aaa[p.first], aaa[p.second]);
        swap(bbb[p.first], bbb[p.second]);
        mov.push_back(p);
    }
    int v = aaa[0];
    for (int i = 1; i < n; i++)
    {
        if (v > aaa[i])
        {
            printf("-1\n");
            return;
        }
        v = aaa[i];
    }
    printf("%d\n", (int)mov.size());
    for (auto &&i : mov)
    {
        printf("%d %d\n", i.first + 1, i.second + 1);
    }
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