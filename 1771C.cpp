#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 3e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

std::vector<int> prime;
bitset<N> is_composite;

void linear_sieve(int n)
{
    is_composite.reset();
    for (int i = 2; i < n; ++i)
    {
        if (!is_composite[i])
            prime.push_back(i);
        for (int j = 0; j < (int)prime.size() && i * prime[j] < n; ++j)
        {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int arr[N];
set<int> vis;

bool ok(int sz)
{
    vis.clear();
    for (int i = 0; i < sz; i++)
    {
        for (auto &&j : prime)
        {
            if (1ll * j * j > arr[i])
            {
                break;
            }
            if (arr[i] % j == 0)
            {
                if (vis.find(j) != vis.end())
                {
                    return true;
                }
                vis.insert(j);
                while (arr[i] % j == 0)
                {
                    arr[i] /= j;
                }
            }
        }
        if (arr[i] > 1 && vis.find(arr[i]) != vis.end())
        {
            return true;
        }
        vis.insert(arr[i]);
    }
    return false;
}

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    printf(ok(n) ? "YES\n" : "NO\n");
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    linear_sieve(N);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}