#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

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
} arr[N], srt[N];

int ind[N], frq[N], pos[N], lg[N];
char str[N];

void count_sort(Suffix *ptr, int sz)
{
    int mx = 0;
    for (int i = 0; i < sz; i++)
    {
        mx = max(mx, ptr[i].r.second + 1);
    }
    if (mx > sz * lg[sz])
    {
        sort(ptr, ptr + sz);
        return;
    }
    memset(frq, 0, sizeof(frq[0]) * (mx + 1));
    for (int i = 0; i < sz; i++)
    {
        frq[ptr[i].r.second + 1]++;
    }
    pos[0] = 0;
    for (int i = 1; i <= mx; i++)
    {
        pos[i] = pos[i - 1] + frq[i - 1];
    }
    for (int i = 0; i < sz; i++)
    {
        srt[pos[ptr[i].r.second + 1]++] = ptr[i];
    }
    copy(srt, srt + sz, ptr);
}

// int frqf[N], frqs[N], posf[N], poss[N];

// void count_sort(int sz)
// {
//     memset(frqf, 0, sizeof(frqf[0]) * (sz + 1));
//     memset(frqs, 0, sizeof(frqs[0]) * (sz + 1));
//     for (int i = 0; i < sz; i++)
//     {
//         frqf[arr[i].r.first]++;
//         frqs[arr[i].r.second + 1]++;
//     }
//     posf[0] = poss[0] = 0;
//     for (int i = 1; i <= sz; i++)
//     {
//         posf[i] = posf[i - 1] + frqf[i - 1];
//         poss[i] = poss[i - 1] + frqs[i - 1];
//     }
//     for (int i = 0; i < sz; i++)
//     {
//         srt[poss[arr[i].r.second + 1]++] = arr[i];
//     }
//     for (int i = 0; i < sz; i++)
//     {
//         arr[posf[srt[i].r.first]++] = srt[i];
//     }
// }

void my_sort(Suffix *ptr, int sz)
{
    for (int i = 0, j = 0; i < sz; i = j)
    {
        for (; j < sz && ptr[i].r.first == ptr[j].r.first; j++)
        {
            // frq[ptr[i].r.second + 1]++;
        }
        if (j - i > 1)
        {
            count_sort(ptr + i, j - i);
        }
    }
}

void calcSuffix()
{
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        arr[i].i = i;
        arr[i].r.first = str[i] - 'a';
        arr[i].r.second = str[(i + 1) % n] - 'a';
    }
    sort(arr, arr + n);
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
            arr[j].r.second = arr[j].i + i < 2 * n - 1 ? arr[ind[(arr[j].i + i) % n]].r.first : -1;
        }
        my_sort(arr, n);
    }
}

void run()
{
    for (int i = 2; i < N; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    scanf("%s", str);
    calcSuffix();
    printf("%s", str + arr[0].i);
    str[arr[0].i] = '\0';
    printf("%s\n", str);
}

int main()
{
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}