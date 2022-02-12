#include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;

// const int N = 1e5 + 10;

bool isPal(std::string &s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

void run()
{
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;
    std::cout << (k == 0 || isPal(s) ? 1 : 2) << '\n';
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}
