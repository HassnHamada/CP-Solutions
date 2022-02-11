#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
typedef long long int ll;

const int N = 5e5;
int arr[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    int n;
    ll t = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        t += arr[i];
    }
    if (t % 3 != 0)
    {
        printf("0\n");
        return 0;
    }
    ll a = t / 3, ans = 0;
    stack<ll> sss;
    for (ll i = 1, j = arr[0]; i < n - 1; j += arr[i], i++)
    {
        if (j == a)
        {
            sss.push(i);
        }
    }
    for (ll i = n - 2, j = arr[n - 1]; !sss.empty() && i > 0; j += arr[i], i--)
    {
        assert(sss.top() <= i);
        if (j == a)
        {
            ans += sss.size();
        }
        if (sss.top() == i)
        {
            sss.pop();
        }
    }
    printf("%lld\n", ans);

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}