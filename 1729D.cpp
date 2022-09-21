#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

int arr[N];

void run()
{
    int n, cat = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    vector<int> pos, neg;
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        if (v > arr[i])
        {
            pos.push_back(v - arr[i]);
        }
        else if (v < arr[i])
        {
            neg.push_back(arr[i] - v);
        }
        else
        {
            cat += 1;
        }
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end(), greater<int>());
    int ans = 0;
    while (!pos.empty())
    {
        if (neg.empty())
        {
            break;
        }
        if (pos.back() >= neg.back())
        {
            ans += 1;
            pos.pop_back();
            neg.pop_back();
        }
        else
        {
            cat += 1;
            pos.pop_back();
        }
    }
    // cout << pos.size() << " " << neg.size() << " " << cat << endl;
    printf("%d\n", ans + (cat + (int)pos.size()) / 2);
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