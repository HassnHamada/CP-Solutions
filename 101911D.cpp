#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <set>
// #include <map>
using namespace std;
typedef long long int ll;

const int N = 2e5 + 10;
map<int, vector<int>> primes, divisors;
int arr[N];
// map<int, set<int>> used;
// int ccc[N];

void add(int n)
{
    // cout << n << endl;
    vector<int> &ref = primes[n];
    if (n % 2 == 0)
    {
        ref.push_back(2);
        while (n % 2 == 0)
        {
            n /= 2;
        }
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        // cout << i << endl;
        if (n % i == 0)
        {
            // cout << i << endl;
            ref.push_back(i);
            // if (i * i != n)
            // {
            //     ref.push_back(n / i);
            // }
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n != 1)
    {
        ref.push_back(n);
    }
    // for (auto &&i : ref)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
}

bool next(int n, vector<int> &vec)
{
    vector<int> &ref = primes[n];
    for (int i = 0; i < vec.size(); i++)
    {
        if (n % (ll)pow(ref[i], (vec[i] + 1)) == 0)
        {
            vec[i] += 1;
            return true;
        }
        vec[i] = 0;
    }
    return false;
}
void run()
{
    int n;
    cin >> n;
    divisors[1].push_back(1);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        if (divisors.find(c) == divisors.end())
        {
            add(c);
            vector<int> &refPrimes = primes[c], &refDivisors = divisors[c];
            vector<int> tem(refPrimes.size());
            do
            {
                ll k = 1;
                for (int j = 0; j < tem.size(); j++)
                {
                    k *= pow(refPrimes[j], tem[j]);
                }
                refDivisors.push_back(k);
            } while (next(c, tem));
        }
        arr[i] = c;
    }
    vector<int> ans(n);
    bool ok = true;
    for (int i = 0; ok && i < n; i++)
    {
        bool newOk = false;
        int val = arr[i];
        if (divisors[val].size())
        {
            newOk = true;
            ans[i] = divisors[val].back();
            divisors[val].pop_back();
        }
        ok = newOk;
    }
    if (ok)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            assert(arr[i] % ans[i] == 0);
            cout << ans[i] << " " << arr[i] / ans[i] << endl;
        }
    }
    else
    {
        cout << "NO\n";
    }
}

int main(int argc, char const *argv[])
{
    // freopen(".\\_input.txt", "r", stdin);
    // freopen(".\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // cout << setprecision(10) << fixed;
    int test = 1;
    // cin >> t;
    while (test--)
    {
        run();
    }
    return 0;
}