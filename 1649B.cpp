#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// const int N = 1e5 + 10;
// int arr[N];

void run()
{
    int n, mx = 0;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        mx = max(mx, v);
        sum += v;
        // scanf("%d", arr + i);
    }
    if (sum == 0)
    {
        printf("0\n");
    }
    else if (sum - mx < mx)
    {
        printf("%lld\n", mx - sum + mx);
    }
    else
    {
        printf("1\n");
    }
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
