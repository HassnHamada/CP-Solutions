#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 1e1 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

// int arr[N];

void run()
{
    int n;
    scanf("%d", &n);
    vector<int> vec;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        if (v == 2)
        {
            vec.push_back(i + 1);
        }
    }
    if (vec.size() & 1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", vec.empty() ? 1 : vec[vec.size() / 2 - 1]);
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