#include <stdio.h>
#include <set>
#include <assert.h>
using namespace std;
typedef long long ll;

bool isPrime(int n)
{
    if (n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i < n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> digits(int n)
{
    vector<int> ret;
    while (n)
    {
        ret.push_back(n % 10);
        n /= 10;
    }
    sort(ret.begin(), ret.end());
    assert((int)ret.size() == 4);
    return ret;
}

bool ok(int a, int b, int c)
{
    vector<int> ad = digits(a), bd = digits(b), cd = digits(c);
    return equal(ad.begin(), ad.end(), bd.begin()) && equal(ad.begin(), ad.end(), cd.begin());
}

void run()
{
    int mx = 10000, mn = 1000;
    for (int i = 1; i <= (mx - mn) / 2; i++)
    {
        for (int j = mn; j <= mx - i * 2; j++)
        {
            int a = j, b = j + i, c = j + i * 2;
            if (!isPrime(a) || !isPrime(b) || !isPrime(c))
            {
                continue;
            }
            if (ok(a, b, c))
            {
                printf("%d %d %d\n", a, b, c);
            }
        }
        // printf("%d\n", i);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    run();
    return 0;
}