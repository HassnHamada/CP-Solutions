#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 1e6;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = rnd.next(2, N);
    printf("%d\n", n);
    for (auto &&i : rnd.distinct(n, n))
    {
        printf("%d%c", i + 1, "\n "[--n ? 1 : 0]);
    }
}