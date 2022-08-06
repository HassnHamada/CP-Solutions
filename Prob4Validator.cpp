#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 1e6;
bitset<N> bs;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);

    int n = inf.readInt(2, N, "n");
    inf.readEoln();
    for (int i = 0; i < n; i++)
    {
        int v = inf.readInt(1, n, "v");
        if (bs[v])
        {
            quit(_wa, "Numbers must be distinct\n");
        }
        bs[v] = 1;
        if (i + 1 < n)
        {
            inf.readSpace();
        }
    }
    inf.seekEof();
    inf.readEof();
}