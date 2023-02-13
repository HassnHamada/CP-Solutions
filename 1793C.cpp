#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 1e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

// pair<int, int> arr[N];
int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    set<int> mn(arr, arr + n);
    set<int, greater<int>> mx(arr, arr + n);
    int ii = 0, jj = n - 1;
    while (ii < jj)
    {
        if (arr[ii] == *mn.begin() || arr[ii] == *mx.begin())
        {
            mn.erase(arr[ii]);
            mx.erase(arr[ii++]);
        }
        else if (arr[jj] == *mn.begin() || arr[jj] == *mx.begin())
        {
            mn.erase(arr[jj]);
            mx.erase(arr[jj--]);
        }
        else
        {
            break;
        }
    }
    if (ii < jj)
    {
        // assert(ii + 2 < jj);
        printf("%d %d\n", ii + 1, jj + 1);
    }
    else
    {
        printf("-1\n");
    }
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}