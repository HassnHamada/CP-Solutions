#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2 + 10, M = 6, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int n, m, val;

void moveh(int ii = 1, int is = 0, int ie = n, int jj = 1, int js = 0, int je = m, int p = 1)
{
    printf("%d %d\n", ii, jj);
    val += 1;
    if (jj + p < je && jj + p > js)
    {
        moveh(ii, is, ie, jj + p, js, je, p);
    }
    else
    {
        if (ii + 1 < ie)
        {
            printf("%d %d\n", ii + 1, jj);
            val += 1;
        }
        if (ii + 2 < ie)
        {
            moveh(ii + 2, is, ie, jj, js, je, -p);
        }
    }
}

void movev(int ii = 1, int is = 0, int ie = n, int jj = 1, int js = 0, int je = m, int p = 1)
{
    printf("%d %d\n", ii, jj);
    val += 1;
    if (ii + p < ie && ii + p > is)
    {
        movev(ii + p, is, ie, jj, js, je, p);
    }
    else
    {
        if (jj + 1 < je)
        {
            printf("%d %d\n", ii, jj + 1);
            val += 1;
        }
        if (jj + 2 < je)
        {
            movev(ii, is, ie, jj + 2, js, je, -p);
        }
    }
}
void imovev(int ii = 1, int is = 0, int ie = n, int jj = 1, int js = 0, int je = m, int p = 1)
{
    printf("%d %d\n", ii, jj);
    val += 1;
    if (ii + p < ie && ii + p > is)
    {
        imovev(ii + p, is, ie, jj, js, je, p);
    }
    else
    {
        if (jj - 1 > js)
        {
            printf("%d %d\n", ii, jj - 1);
            val += 1;
        }
        if (jj - 2 > js)
        {
            imovev(ii, is, ie, jj - 2, js, je, -p);
        }
    }
}

void run()
{
    scanf("%d%d", &n, &m);
    if (m == 1 || n == 1)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", n * m / 2 - 1);
        if (n & 1)
        {
            if (m & 1)
            {
                if (n % 4 == 3)
                {
                    moveh(1, 0, n, 1, 0, 3);
                }
                if (n % 4 == 1)
                {
                    moveh(1, 0, n, 2, 0, 3, -1);
                }
                if (m > 3)
                {
                    if ((m - 3) % 4)
                    {
                        imovev(1, 0, n, m - 1, 3, m, 1);
                    }
                    else
                    {
                        imovev(n - 1, 0, n, m - 1, 3, m, -1);
                    }
                    printf("%d %d\n", n - 1, 3);
                    val += 1;
                }
            }
            else
            {
                movev();
            }
        }
        else
        {
            moveh();
        }
        // cout << val << " " << n * m / 2 << endl;
        assert(val == n * m / 2 - 1);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}