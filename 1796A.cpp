#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10, M = 2, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], tem[M][N];

void run()
{
    int n;
    string s;
    cin >> n >> s;
    // for (int i = 1; i <= 100; i++)
    // {
    //     if (i % 3 == 0)
    //     {
    //         s.push_back('F');
    //     }
    //     if (i % 5 == 0)
    //     {
    //         s.push_back('B');
    //     }
    // }
    // cout << s << endl;
    cout << (string("FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFB").find(s) == string::npos ? "NO\n" : "YES\n");
}

int main()
{
    // freopen("_output.txt", "w", stdout);
    // freopen("_input.txt", "r", stdin);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}