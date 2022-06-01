#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;
int arr[N];
char str[N];

void run()
{
    int n, k;
    scanf("%d%s%d", &n, str, &k);
    set<char> kkk;
    for (int i = 0; i < k; i++)
    {
        char c;
        scanf(" %c", &c);
        kkk.insert(c);
    }
    int sz = 1;
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        if (kkk.find(str[i]) != kkk.end())
        {
            arr[sz++] = j;
            j = 0;
        }
    }
    // for (int i = 0; i < sz; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    printf("%d\n", *max_element(arr, arr + sz));
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}