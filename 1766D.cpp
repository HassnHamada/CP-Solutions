#include <bits/stdc++.h>
// using namespace std;
typedef long long ll;

const int N = 1e7 + 10, M = 1e6 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

std::vector<int> prime, div_;
std::bitset<N> is_composite;

void linear_sieve(int n)
{
    div_.resize(n, 1);
    is_composite.reset();
    for (int i = 2; i < n; ++i)
    {
        if (!is_composite[i])
            prime.push_back(i);
        for (int j = 0; j < (int)prime.size() && i * prime[j] < n; ++j)
        {
            is_composite[i * prime[j]] = true;
            div_[i * prime[j]] = i;
            if (i % prime[j] == 0)
                break;
        }
    }
}

std::vector<int> get_div(int n)
{
    std::set<int> ret;
    while (n != 1)
    {
        ret.insert(n / div_[n]);
        n = div_[n];
    }
    return std::vector<int>(ret.begin(), ret.end());
}

void run()
{
    int x, y;
    scanf("%d%d", &x, &y);
    int d = y - x, ans = INF;
    for (auto &&i : get_div(d))
    {
        ans = std::min(ans, (i - x % d % i) % i);
    }
    printf("%d\n", d == 1 ? -1 : ans);
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