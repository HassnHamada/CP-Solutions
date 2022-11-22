    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    const int N = 5e1 + 10, M = 100, MOD = 998244353, HV = 151, INF = 0x3f3f3f3f;

    void run()
    {
        int n;
        scanf("%d", &n);
        // 1 1 2 2 3 3  4  4  5  5  6  6  7  7  8 8
        // 1 2 4 6 9 12 16 20 25 30 36 42 49 56
        printf("%d\n", (n + 1) / 2);
    }

    int main()
    {
        // freopen("_input.txt", "r", stdin);
        // freopen("_output.txt", "w", stdout);
        int t = 1;
        scanf("%d", &t);
        while (t--)
        // while (scanf("%d", &n), n)
        {
            run();
        }
        return 0;
    }
