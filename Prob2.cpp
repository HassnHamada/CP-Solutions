#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int ans[N][N];

void run()
{
    // Input
    //      first line q
    //      next q lines contains 1 of 2 queries
    //      first number t is represent the query
    //      if t == 1 it will be folowed by 3 numbers x, y, r the postion of the circle center and its radius
    //      this query adds a circle with the given postion and radius
    //      if t == 2 it will be folowed by 1 numbers d the index of the circle to delete
    //      the index is equal to when it was enterd it is grantred the d exists
    // Output q lines after each query the area coverd by the circles
    // Testcase Input:
    // 8
    // 1 0 0 3
    // 1 0 2 2
    // 2 2
    // 1 0 -2 2
    // 1 5 5 1
    // 2 3
    // 2 1
    // 2 4
    // Output:
    // 28.27433
    // 31.52022
    // 28.27433
    // 31.52022
    // 107.80107
    // 104.55518
    // 78.53981
    // 0
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}