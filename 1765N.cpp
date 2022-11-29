#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char num[N];

void run()
{
    scanf("%s", num);
    int n = strlen(num), k;
    scanf("%d", &k);
    stack<char> stk;
    int mn = 0;
    for (int i = 0; i <= k; i++)
    {
        if (num[i] == '0')
        {
            continue;
        }
        if (num[i] < num[mn])
        {
            mn = i;
        }
    }
    k -= mn;
    stk.push(num[mn]);
    int i = mn + 1;
    for (; k && i < n; i++)
    {
        assert(!stk.empty());
        while (k && !stk.empty() && num[i] < stk.top())
        {
            if (num[i] == '0' && (int)stk.size() == 1)
            {
                break;
            }
            k--;
            stk.pop();
        }
        stk.push(num[i]);
    }
    assert(k == 0 || i == n);
    while (i < n)
    {
        stk.push(num[i++]);
    }
    assert(k >= 0);
    while (k--)
    {
        stk.pop();
    }
    assert(!stk.empty());
    int sz = 0;
    while (!stk.empty())
    {
        num[sz++] = stk.top();
        stk.pop();
    }
    num[sz] = '\0';
    reverse(num, num + sz);
    printf("%s\n", num);
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}