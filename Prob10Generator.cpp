#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 1e5;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    string s = rnd.next("[a-z]{1,100000}");
    int n = s.size();
    printf("%s\n", s.c_str());
    int q = rnd.next(1, N);
    printf("%d\n", q);
    while (q--)
    {
        int l = rnd.next(1, n);
        int r = rnd.next(l, n);
        int k = rnd.next(1, r - l + 1);
        printf("%d %d %d\n", l, r, k);
    }
}