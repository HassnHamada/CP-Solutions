#include <bits/stdc++.h>
// #include <set>
// #include <iostream>
using namespace std;
// typedef long long int ll;

const int N = 2e5 + 10;
int arr[N], n;
multiset<int> rrr, bbb;

bool ok()
{
    for (int i = 1; i <= n; i++)
    {
        multiset<int>::iterator itb = bbb.lower_bound(i),
                                itr = rrr.upper_bound(i);
        if (itb == bbb.end() && itr == rrr.begin())
        {
            return false;
        }
        else if (itb != bbb.end())
        {
            bbb.erase(itb);
        }
        else
        {
            rrr.erase(rrr.begin());
        }
    }
    return true;
}

void run()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        // sss.insert(v);
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        (c == 'R' ? rrr : bbb).insert(arr[i]);
    }
    cout << (ok() ? "YES" : "NO") << endl;
    rrr.clear();
    bbb.clear();
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

