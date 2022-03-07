#include <bits/stdc++.h>
using namespace std;
// typedef long long int ll;

const int N = 1e3 + 10;
int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int i = 0, j = n - 1;
    while (i < j && arr[i + 1])
    {
        i += 1;
    }
    while (i < j && arr[j - 1])
    {
        j -= 1;
    }
    printf("%d\n", j - i);
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
