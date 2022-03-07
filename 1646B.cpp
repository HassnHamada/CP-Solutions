#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 2e5 + 10;
int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    ll b = 0, r = 0, i = 0, j = n;
    for (; i < j;)
    {
        if (r <= b)
        {
            r += arr[--j];
        }
        else if (n - j >= i)
        {
            b += arr[i++];
        }
        else
        {
            break;
        }
    }
    printf(r > b && n - j < i ? "YES\n" : "NO\n");
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
