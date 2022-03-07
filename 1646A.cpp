#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// const int N = 1e5 + 10;
// int arr[N];

void run()
{
    ll n, s;
    scanf("%lld%lld", &n, &s);
    printf("%lld\n", s / n / n);
}

int main(int argc, char const *argv[])
{
    // freopen("./_input.txt", "r", stdin);
    // freopen("./_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
