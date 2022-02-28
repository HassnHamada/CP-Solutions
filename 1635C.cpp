#include <bits/stdc++.h>
using namespace std;
// typedef long long int ll;

const int N = 2e5 + 10;
int arr[N];

struct Move
{
    int x, y, z;
};

{
}

void run()
{
    int n, sq;
    scanf("%d", &n);
    sq = ceil(sqrt(n));
    map<int, int> mmm[sq];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        mmm[i / sq][arr[i]]++;
    }
    vector<struct Move> ans;
    for (int i = 0; i < n - 2; i++)
    {
        mmm[i / sq][arr[i]]--;
        myMin();
        myMax();
        // if (mmm[arr[i]] == 0)
        // {
        //     mmm.erase(arr[i]);
        // }
        if (arr[i] > arr[i + 1])
        {
            // int l,
        }
    }
    // for (int i = 1; i < n - 1; i++)
    // {
    //     if (arr[i] > max(arr[i - 1], arr[i + 1]))
    //     {
    //         arr[i + 1] = max(arr[i], i < n - 2 ? arr[i + 2] : 0);
    //         ans++;
    //     }
    // }
    // printf("%d\n", ans);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d%c", arr[i], " \n"[i == n - 1]);
    // }
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
