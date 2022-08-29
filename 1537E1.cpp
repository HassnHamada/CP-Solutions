#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e3 + 10, M = 2e2 + 10, MOD = 5e6, HV = 151, INF = 0x3f3f3f3f;

struct Suffix
{
    int i;
    pair<int, int> r;
    bool operator<(const Suffix &other) const
    {
        if (this->r.first == other.r.first)
        {
            return this->r.second < other.r.second;
        }
        return this->r.first < other.r.first;
    }
} arr[N];

char str[N];

void calcSuffix()
{
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        arr[i].i = i;
        arr[i].r.first = str[i] - 'a';
        arr[i].r.second = i + 1 < n ? str[i + 1] - 'a' : -1;
    }
    sort(arr, arr + n);
    vector<int> ind(n);
    for (int i = 2; i < n; i *= 2)
    {
        pair<int, int> prv = arr[0].r;
        arr[0].r.first = ind[arr[0].i] = 0;
        for (int j = 1; j < n; j++)
        {
            ind[arr[j].i] = j;
            if (arr[j].r == prv)
            {
                arr[j].r.first = arr[j - 1].r.first;
            }
            else
            {
                prv = arr[j].r;
                arr[j].r.first = arr[j - 1].r.first + 1;
            }
        }
        for (int j = 0; j < n; j++)
        {
            arr[j].r.second = arr[j].i + i < n ? arr[ind[arr[j].i + i]].r.first : -1;
        }
        sort(arr, arr + n);
    }
}

void run()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", str);
    calcSuffix();
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", str + arr[i].i);
    }
}

int main()
{
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}