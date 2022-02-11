#include <bits/stdc++.h>
// #include "stdc++.h"
using namespace std;
// typedef long long int ll;

const int N = 2e5 + 10;
int arr[N];

bool kalindrome(int i, int j, int d = 0)
{
    if (i >= j)
    {
        return true;
    }
    if (arr[i] == arr[j])
    {
        return kalindrome(i + 1, j - 1, d);
    }
    if (d)
    {
        return (arr[i] == d && kalindrome(i + 1, j, d)) || (arr[j] == d && kalindrome(i, j - 1, d));
    }
    return kalindrome(i + 1, j, arr[i]) || kalindrome(i, j - 1, arr[j]);
}

void run()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << (kalindrome(0, n - 1) ? "YES\n" : "NO\n");
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}