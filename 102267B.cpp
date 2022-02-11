#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 5e6 + 10;
// const int N = 1e7 + 10;
bitset<N> prime;

void fastSieve(int n, vector<int> &vec)
{
    prime.set();
    for (ll i = 3; i * i <= n; i += 2)
    {
        for (ll j = i * i; prime[i / 2] && j <= n; j += 2 * i)
        {
            prime[j / 2] = 0;
        }
    }
    vec.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        if (prime[i / 2])
        {
            vec.push_back(i);
        }
    }
}

void sieve(int n, vector<int> &vec)
{
    prime.set();
    for (ll i = 2; i * i <= n; i++)
    {
        for (ll j = i * i; prime[i] && j <= n; j += i)
        {
            prime[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            vec.push_back(i);
        }
    }
}

bool in(int v, vector<int> &vec)
{
    return *lower_bound(vec.begin(), vec.end(), v) == v;
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> vec;
    fastSieve(n, vec);
    if (in(2, vec) && in(n - 2, vec))
    {
        printf("2 %d\n", n - 2);
        return 0;
    }
    for (int i = 3; n % 2 == 0 && i <= n; i += 2)
    {
        if (in(i, vec) && in(n - i, vec))
        {
            printf("%d %d\n", i, n - i);
            return 0;
        }
    }
    printf("-1\n");
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}