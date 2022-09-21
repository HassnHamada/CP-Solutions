#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 5e2 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

bitset<N << 2> vis[N][N];
bitset<N * N> mat;

void solve(int cx, int cy, int cn, int d)
{
    if (cn == 0)
    {
        mat.set(cx * N + cy);
        return;
    }
    if (vis[cx][cy][cn + (N * d << 1)])
    {
        return;
    }
    vis[cx][cy][cn + (N * d << 1)] = true;
    solve(cx + d, cy + (d ^ 1), cn - 1, d ^ 1);
    solve(abs(cx - d), abs(cy - (d ^ 1)), cn - 1, d ^ 1);
}

void run()
{
    int n;
    scanf("%d", &n);
    solve(0, 0, n, 0);
    int ans = (4 * mat.count()) - 3 * mat[0];
    for (int i = 1; i < N; i++)
    {
        ans -= 2 * (mat[i * N] + mat[i]);
    }
    printf("%d\n", ans << (n & 1));
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