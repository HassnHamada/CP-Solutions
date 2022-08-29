#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 1e5;

string s;
struct Q
{
    int l, r, k;
} query[N];

// int q, n;
int q;

int ok[N];

inline void readAndCheckAnswer(InStream &in)
{
    for (int i = 0; i < q; i++)
    {
        int res = in.readInt(query[i].l, query[i].r - query[i].k + 1, "res");
        if (i + 1 < q)
        {
            in.readEoln();
        }
        // if (res < query[i].l && res > query[i].r - query[i].k + 1)
        // {
        //     in.quitf(_wa, "The first character index must bigger than or equal %d and the last character index must be less than or equal %d found %d", query[i].l, query[i].r, res);
        // }
        if (res == ok[i])
        {
            continue;
        }
        for (int j = 0; j < query[i].k; j++)
        {
            if (s[j + res - 1] != s[j + ok[i] - 1])
            {
                in.quitf(_wa, "Worong answer smaller answer exists");
            }
        }
    }
    in.seekEof();
    in.readEof();
}

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    // string s = inf.readToken("[a-z]+", "s");
    // inf.readEoln();
    string s = inf.readString("[a-z]+", "s");
    q = inf.readInt(1, N, "q");
    for (int i = 0; i < q; i++)
    {
        query[i].l = inf.readInt(1, N, "l");
        query[i].r = inf.readInt(1, N, "r");
        query[i].k = inf.readInt(1, N, "k");
    }
    inf.seekEof();
    inf.readEof();
    for (int i = 0; i < q; i++)
    {
        ok[i] = ans.readInt(1, N, "v");
    }
    ans.seekEof();
    ans.readEof();
    readAndCheckAnswer(ouf);
    quitf(_ok, "Passed all tests");
}