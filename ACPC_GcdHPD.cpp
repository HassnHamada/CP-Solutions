#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 1e5 + 10;
int fact[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void getFact(int n, vector<int> &ret)
{
    while (n ^ 1)
    {
        ret.push_back(n / fact[n]);
        n = fact[n];
    }
}

int getK(int n, int k, bool rev)
{
    vector<int> vec;
    getFact(n, vec);
    if (vec.size() < k)
    {
        return -1;
    }
    if (rev)
    {
        reverse(vec.begin(), vec.end());
    }
    int ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans *= vec[i];
    }
    return ans;
}

int gcdHPD(int i, int j, int k)
{
    int iv = getK(i, k, false), jv = getK(j, k, true);
    return ~iv && ~jv ? iv * jv : -1;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    freopen(".\\c++\\_input.txt", "r", stdin);
    freopen(".\\c++\\_output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    iota(fact, fact + N, 0);
    for (int i = 2; i < N; i++)
    {
        if (fact[i] == i)
        {
            fact[i] = 1;
            for (ll j = 1ll * i * i; j < N; j += i)
            {
                if (fact[j] != j)
                {
                    continue;
                }
                fact[j] = j / i;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, ans = 0;
        cin >> n >> k;
        for (int i = 1 << k; i <= n; i++)
        {
            int iv = getK(i, k, true);
            if (iv == -1)
            {
                continue;
            }
            for (int j = iv; j <= n; j += iv)
            {
                int jv = getK(j, k, false);
                if (jv == -1 || gcd(i, j) != iv * jv)
                {
                    continue;
                }
                ans += 1;
            }
        }
        cout << ans << endl;
    }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
