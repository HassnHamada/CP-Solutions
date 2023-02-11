#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char inp[N];

bool ok(int n)
{
    std::set<std::string> mp;
    for (int i = 1; i < n - 1; i++)
    {
        if (mp.find(std::string(inp + i, inp + i + 2)) == mp.end())
        {
            mp.insert(std::string(inp + i - 1, inp + i + 1));
            continue;
        }
        return true;
    }
    return false;
}

void run()
{
    int n;
    scanf("%d%s", &n, inp);
    printf(ok(n) ? "YES\n" : "NO\n");
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