#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, tot = 0;
        scanf("%d", &n);
        for (int i = 0, v; i < n; i++)
        {
            scanf("%d", &v);
            tot += v;
        }
        if (tot == n)
        {
            printf("0\n");
        }
        else if (tot < n)
        {
            printf("1\n");
        }
        else
        {
            printf("%d\n", tot - n);
        }
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}