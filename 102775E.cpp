#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e0 + 10, M = 7, L = 3, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f, EMP = -1;

char str[N], aaa[M][N] = {"stone", "scissors", "paper", "pliers", "knife", "ax", "controller"};
int bbb[M][L] = {{1, 6, 4},
                 {2, 3, 6},
                 {5, 0, 3},
                 {0, 4, 5},
                 {6, 2, 1},
                 {4, 1, 0},
                 {3, 5, 2}};

bool win(int i, int j)
{
    return find(bbb[i], bbb[i] + L, j) - bbb[i] < L;
}

int find()
{
    for (int i = 0; i < M; i++)
    {
        if (strcmp(str, aaa[i]) == 0)
        {
            return i;
        }
    }
    assert(false);
    return -1;
}

void run()
{
    scanf("%s", str);
    int i = find();
    scanf("%s", str);
    int j = find();
    bool a = win(i, j), b = win(j, i);
    if (a)
    {
        assert(!b);
        printf("1\n");
    }
    else if (b)
    {
        printf("-1\n");
    }
    else
    {
        printf("0\n");
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}