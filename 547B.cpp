#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];
map<int, int, greater<int>> lif;

void prn(stack<pair<int, int>> stk)
{
    while (!stk.empty())
    {
        auto [a, b] = stk.top();
        cout << a << " " << b << endl;
        stk.pop();
    }
    cout << "------------------\n";
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    stack<pair<int, int>> stk;
    for (int i = 0; i <= n; i++)
    {
        pair<int, int> t = {arr[i], i};
        while (!stk.empty() && arr[i] <= stk.top().first)
        {
            auto [a, b] = stk.top();
            lif[a] = max(lif[a], i - b);
            assert(b < t.second);
            t.second = b;
            stk.pop();
        }
        stk.push(t);
    }
    // for (auto &&[i, j] : lif)
    // {
    //     cout << i << " " << j << endl;
    // }
    for (int i = 0; i < n; i++)
    {
        while (lif.begin()->second <= i)
        {
            lif.erase(lif.begin());
            assert(!lif.empty());
        }
        printf("%d%c", lif.begin()->first, " \n"[i + 1 == n]);
    }
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

// 1  5
// 2  3
// 3  2
// 4  8
// 5  1
// 7  3
// 8  7
// 10 2
// 11 7
// 13 14
// 16 15