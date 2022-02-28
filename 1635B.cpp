#include <bits/stdc++.h>
using namespace std;
// typedef long long int ll;

const int N = 2e5 + 10;
int arr[N];

void run()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > max(arr[i - 1], arr[i + 1]))
        {
            arr[i + 1] = max(arr[i], i < n - 2 ? arr[i + 2] : 0);
            ans++;
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
    {
        printf("%d%c", arr[i], " \n"[i == n - 1]);
    }
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}
