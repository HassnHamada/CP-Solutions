#include <bits/stdc++.h>
// #include <chrono>
// #include "./stdc++.h"
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 101;
char num1[N], num2[N];

int readNum(char *num)
{
    for (int i = 0;; i++)
    {
        scanf("%c", num + i);
        if (num[i] == '\n')
        {
            return i;
        }
        num[i] -= '0';
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    int n = readNum(num1);
    readNum(num2);
    for (int i = 0; i < n; i++)
    {
        printf("%c", num1[i] != num2[i] ? '1' : '0');
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}