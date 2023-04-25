#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

void run()
{
    char a, b, c, d;
    scanf("\n%c%c%c%c", &a, &b, &c, &d);
    set<int> sss;
    sss.insert(a);
    sss.insert(b);
    sss.insert(c);
    sss.insert(d);
    if (sss.size() == 1)
    {
        printf("-1\n");
    }
    else if (sss.size() == 2)
    {
        if (a != c)
        {
            swap(b, c);
        }
        if (a != d)
        {
            swap(b, d);
        }
        assert(a != b);
        int c1 = 1, c2 = 1;
        c1 += c == a;
        c1 += d == a;
        c2 += c == b;
        c2 += d == b;
        assert(c1 + c2 == 4);
        if (c1 == 2 && c2 == 2)
        {
            printf("4\n");
        }
        else
        {
            printf("6\n");
        }
    }
    else
    {
        printf("4\n");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}