#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

// const int N = 101;
// char num1[N], num2[N];

void printUpDown(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i);
    }
    for (int i = n; ~i; i--)
    {
        printf("%d%c", i, " \n"[i == 0]);
    }
}

void printSp(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print(int cn, int mn)
{
    if (cn == 0)
    {
        printUpDown(mn);
        return;
    }
    printSp(cn * 2);
    printUpDown(mn - cn);
    print(cn - 1, mn);
    printSp(cn * 2);
    printUpDown(mn - cn);
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    int n;
    cin >> n;
    print(n, n);
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}