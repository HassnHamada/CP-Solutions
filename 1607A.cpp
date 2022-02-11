#include <bits/stdc++.h>
using namespace std;

const int N = 26;
int arr[N];

void run()
{
    string s;
    cin >> s;
    for (int i = 0; i < N; i++)
    {
        arr[s[i] - 'a'] = i;
    }
    cin >> s;
    int p = arr[s[0] - 'a'], ans = 0;
    for (int i = 1; i < s.size(); i++)
    {
        ans += abs(p - arr[s[i] - 'a']);
        p = arr[s[i] - 'a'];
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        run();
    }
    return 0;
}
