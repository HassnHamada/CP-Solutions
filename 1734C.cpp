#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 1e9, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char inp[N];

void run()
{
    int n;
    scanf("%d", &n);
    scanf("%s", inp + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            if (inp[j] == '0')
            {
                // cout << j << " " << i << endl;
                ans += i;
                inp[j] = '2';
            }
            else if (inp[j] == '1')
            {
                break;
            }
            else if (inp[j] == '2')
            {
                continue;
            }
            else
            {
                assert(false);
            }
        }
    }
    printf("%lld\n", ans);
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