#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 30, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

char inp[N];

void run()
{
    int n;
    char c;
    scanf("%d %c%s", &n, &c, inp);
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        if (inp[i] == 'g')
        {
            vec.push_back(i);
        }
    }
    vec.push_back(n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (inp[i] == c)
        {
            auto it = lower_bound(vec.begin(), vec.end(), i);
            ans = max(ans, (*it) - i + ((*it) == n ? *vec.begin() : 0));
        }
    }
    printf("%d\n", ans);
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
