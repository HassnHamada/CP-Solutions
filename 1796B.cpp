#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 10, M = 2, L = 30, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N], tem[M][N];

void run()
{
    string a, b;
    cin >> a >> b;
    if (*a.begin() == *b.begin())
    {
        cout << "YES\n"
             << (*a.begin()) << "*\n";
    }
    else if (*a.rbegin() == *b.rbegin())
    {
        cout << "YES\n*" << (*a.rbegin()) << "\n";
    }
    else
    {
        for (int i = 0; i <= (int)a.size() - 2; i++)
        {
            string s = a.substr(i, 2);
            if (b.find(s) != string::npos)
            {
                cout << "YES\n*" << s << "*\n";
                return;
            }
        }
        cout << "NO\n";
    }
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