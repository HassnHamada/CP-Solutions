#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

// const int N = 2e5 + 10;
// int bit[N];

// void add(int x, int v = 1)
// {
//     for (int i = x; i < N; i += i & -i)
//     {
//         bit[i] += v;
//     }
// }

// int get(int x)
// {
//     int ret = 0;
//     for (int i = x; i; i -= i & -i)
//     {
//         ret += bit[i];
//     }
//     return ret;
// }

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    int l, p, q;
    scanf("%d%d%d", &l, &p, &q);
    printf("%.10f\n", 1.0 * l * p / (p + q));

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}