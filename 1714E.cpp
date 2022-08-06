#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

pair<int, int> arr[N];
int n;

bool solve(int v)
{
    for (int i = 0; i < n; i++)
    {
        while (arr[i].second != v)
        {
            int w = 2 * arr[i].second;
            arr[i].first += w / 10;
            arr[i].second = w % 10;
        }
    }
    int p = arr[0].first & 1;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i].first & 1) != p)
        {
            return false;
        }
    }
    return true;
}

void run()
{
    scanf("%d", &n);
    set<int> sss;
    for (int i = 0; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        arr[i].first = v / 10;
        arr[i].second = v % 10;
        sss.insert(v % 10);
    }
    bool ok = false;

    if (sss.count(0))
    {
        if (arr[0].second == 5)
        {
            arr[0].first += 1;
            arr[0].second = 0;
        }
        ok = arr[0].second == 0;
        for (int i = 1; ok && i < n; i++)
        {
            if (arr[i].second == 5)
            {
                arr[i].first += 1;
                arr[i].second = 0;
            }
            if (arr[i].second % 5 != 0 || arr[i] != arr[i - 1])
            {
                ok = false;
            }
        }
    }
    else if (sss.count(5))
    {
        ok = arr[0].second == 5;
        for (int i = 1; ok && i < n; i++)
        {
            assert(arr[i].second);
            if (arr[i].second != 5 || arr[i] != arr[i - 1])
            {
                ok = false;
            }
        }
    }
    else
    {
        for (int i = 2; !ok && i <= 8; i += 2)
        {
            ok = solve(i);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].first << " : " << arr[i].second << endl;
    // }
    // cout << "-------------------\n";
    printf(ok ? "Yes\n" : "No\n");
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
