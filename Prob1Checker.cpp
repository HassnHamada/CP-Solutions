#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 1e3;

int n, m, x, y;
int acc;
bitset<N * N> bs;

inline void readAndCheckAnswer(InStream &in)
{
    int a = 0, b = 0;
    int v = in.readInt(-1, n * m, "v");
    if (v == -1)
    {
        a = b = -1;
    }
    else
    {
        if (x == 1)
        {
            a += v;
        }
        if (y == 1)
        {
            b += v;
        }
        bs[v] = 1;
        if (1 < n)
        {
            in.readSpace();
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i ? 0 : 1; j < m; j++)
            {
                v = in.readInt(1, n * m, "v");
                if (bs[v])
                {
                    in.quitf(_wa, "Not all numbers are distinct\n");
                }
                bs[v] = 1;
                if (i + 1 == x)
                {
                    a += v;
                }
                if (j + 1 == y)
                {
                    b += v;
                }
                if (j + 1 < m)
                {
                    in.readSpace();
                }
            }
            if (i + 1 < n)
            {
                in.readEoln();
            }
        }
    }
    if (acc == -1)
    {
        if (a != -1)
        {
            in.quitf(_wa, "Worng answer\n");
        }
    }
    else
    {
        if (a == -1)
        {
            in.quitf(_wa, "Worng answer\n");
        }
        else if (a != b)
        {
            in.quitf(_wa, "Sum of row %d not equal Sum of column %d\n", x, y);
        }
    }
    in.seekEof();
    in.readEof();
}

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    n = inf.readInt(1, N, "n");
    inf.readSpace();
    m = inf.readInt(1, N, "m");
    inf.readSpace();
    x = inf.readInt(1, n, "x");
    inf.readSpace();
    y = inf.readInt(1, m, "y");
    inf.seekEof();
    inf.readEof();
    acc = ans.readInt(-1, n * m, "v");
    readAndCheckAnswer(ouf);
    quitf(_ok, "Passed all tests");
}