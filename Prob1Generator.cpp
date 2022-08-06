#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 1e3;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = rnd.next(1, N), m = rnd.next(1, N);
    int x = rnd.next(1, n), y = rnd.next(1, m);
    printf("%d %d %d %d\n", n, m, x, y);
}