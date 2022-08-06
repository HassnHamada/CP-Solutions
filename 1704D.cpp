#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

vector<ll> arr[N];
int n, m;

bool cmp(vector<ll> v1, vector<ll> v2)
{
    for (int i = 0; i < m - 2; i++)
    {
        if (v1[i] == v2[i])
        {
            continue;
        }
        if (v1[i] < v2[i])
        {
            swap(v1, v2);
        }
        ll t = v1[i] - v2[i];
        v1[i] -= t;
        v1[i + 1] += 2 * t;
        v1[i + 2] -= t;
    }
    bool ok = true;
    for (int i = m - 2; ok && i < m; i++)
    {
        ok = v1[i] == v2[i];
    }
    return ok;
}

// bool cnv(vector<ll> &v1, vector<ll> &v2)
// {
//     for (int i = 0; i < m - 2; i++)
//     {
//         if (v1[i] == v2[i])
//         {
//             continue;
//         }
//         if (v1[i] < v2[i])
//         {
//             swap(v1, v2);
//         }
//         ll t = v1[i] - v2[i];
//         v1[i] -= t;
//         v1[i + 1] += 2 * t;
//         v1[i + 2] -= t;
//     }
//     bool ok = true;
//     for (int i = m - 2; ok && i < m; i++)
//     {
//         ok = v1[i] == v2[i];
//     }
//     return ok;
// }

ll count(vector<ll> &v1, vector<ll> &v2)
{
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (v1[i] == v2[i])
        {
            continue;
        }
        if (v1[i] < v2[i])
        {
            ll t = v2[i] - v1[i];
            v2[i] -= t;
            v2[i + 1] += 2 * t;
            v2[i + 2] -= t;
            // cout << i << " " << t << endl;
            // ans += t;
        }
        else
        {
            ll t = v1[i] - v2[i];
            cout << i << " " << t << endl;
            v1[i] -= t;
            v1[i + 1] += t;
            v1[i + 2] += t;
            v1[i + 4] -= t;
            ans += t;
        }
    }
    for (auto &&i : v1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto &&i : v2)
    {
        cout << i << " ";
    }
    cout << endl;

    return ans;
}

void run()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        arr[i].clear();
        for (int j = 0, v; j < m; j++)
        {
            scanf("%d", &v);
            arr[i].push_back(v);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << i << " " << j << " " << cmp(arr[j], arr[i]) << endl;
    //     }
    // }
    // cout << "-------------------------\n";
    int k = -1;
    for (int i = 1; i < n; i++)
    {
        bool c = cmp(arr[0], arr[i]);
        if (!c)
        {
            if (i > 1 || cmp(arr[0], arr[n - 1]))
            {
                k = i;
            }
            else
            {
                k = 0;
            }
            break;
        }
    }
    // cnv(arr[k == 0 ? n - 1 : 0], arr[k == 1 ? n - 1 : 1]);
    // for (int i = 0; i < m; i++)
    // {
    //     cout << arr[0][i] << " ";
    // }
    // cout << endl;

    ll ans = count(arr[k], arr[k == 0 ? 1 : 0]);
    printf("%d %lld\n", k + 1, ans);
    // std::cout << k << endl;
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}
