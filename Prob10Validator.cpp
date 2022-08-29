#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 1e5;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);

    // string s = inf.readToken("[a-z]+", "s");
    // inf.readEoln();
    string s = inf.readString("[a-z]+", "s");
    int n = s.size();
    if (n > N)
    {
        quitf(_wa, "String s is too big\n");
    }
    int q = inf.readInt(1, N, "q");
    inf.readEoln();
    for (int i = 0; i < q; i++)
    {
        int l = inf.readInt(1, n, "l");
        inf.readSpace();
        int r = inf.readInt(l, n, "r");
        inf.readSpace();
        int k = inf.readInt(1, r - l + 1, "k");
        if (i + 1 < q)
        {
            inf.readEoln();
        }
    }
    inf.seekEof();
    inf.readEof();
}