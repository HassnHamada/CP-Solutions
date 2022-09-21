#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

const int N = 2e5 + 10, M = 25, L = 4, MOD = 9, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    vector<pair<ll, ll>> v1(M);
    for (int i = 0; i < M; i++)
    {
        printf("? 1 %d\n", i + 2);
        fflush(stdout);
        scanf("%lld", &v1[i].first);
        printf("? %d 1\n", i + 2);
        fflush(stdout);
        scanf("%lld", &v1[i].second);
    }
    for (int i = 0; i < M; i++)
    {
        if (v1[i].first == -1)
        {
            assert(v1[i].second == -1);
            printf("! %d\n", i + 1);
            fflush(stdout);
            break;
        }
        if (v1[i].first != v1[i].second)
        {
            printf("! %lld\n", v1[i].first + v1[i].second);
            fflush(stdout);
            break;
        }
    }
    assert(false);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}