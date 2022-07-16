#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10, M = 1e2 + 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char ans[N];
vector<int> vec;
map<pair<int, int>, int> mmm;

void run()
{
    int n, m = 1;
    scanf("%d", &n);
    while (m <= n)
    {
        printf("? 1 %d\n", m);
        fflush(stdout);
        scanf("\n%c", ans + m);
        vec.push_back(m);
        assert((int)vec.size() <= 26);
        int ii = m, jj = n;
        while (ii < jj)
        {
            int v = (ii + jj + 1) / 2, w;
            assert(v <= jj);
            if (mmm.find({1, v}) == mmm.end())
            {
                printf("? 2 1 %d\n", v);
                fflush(stdout);
                scanf("%d", &w);
                mmm.insert({{1, v}, w});
            }
            else
            {
                w = mmm[{1, v}];
            }
            if (w > (int)vec.size())
            {
                jj = v - 1;
            }
            else
            {
                ii = v;
            }
        }
        m = ii + 1;
    }
    for (int i = 1; i <= n;)
    {
        if (ans[i])
        {
            i += 1;
            continue;
        }
        int ii = i, jj = n;
        while (ii < jj)
        {
            int v = (ii + jj + 1) / 2, w;
            assert(v <= jj);
            if (mmm.find({i, v}) == mmm.end())
            {
                printf("? 2 %d %d\n", i, v);
                fflush(stdout);
                scanf("%d", &w);
                mmm.insert({{i, v}, w});
            }
            else
            {
                w = mmm[{i, v}];
            }

            if (w > 1)
            {
                jj = v - 1;
            }
            else
            {
                ii = v;
            }
        }
        m = ii;
        ii = 0, jj = vec.size() - 1;
        while (ii <= jj)
        {
            int v = (ii + jj + 1) / 2, w, k;
            assert(vec[v] != i);
            if (vec[v] > i)
            {
                continue;
            }
            if (mmm.find({vec[v], m}) == mmm.end())
            {
                printf("? 2 %d %d\n", vec[v], m);
                fflush(stdout);
                scanf("%d", &w);
                mmm.insert({{vec[v], m}, w});
            }
            else
            {
                w = mmm[{vec[v], m}];
            }
            if (mmm.find({vec[v] + 1, m}) == mmm.end())
            {
                printf("? 2 %d %d\n", vec[v] + 1, m);
                fflush(stdout);
                scanf("%d", &k);
                mmm.insert({{vec[v] + 1, m}, k});
            }
            else
            {
                k = mmm[{vec[v] + 1, m}];
            }
            if (w == k)
            {
                while (i <= m)
                {
                    ans[i++] = ans[vec[v]];
                }
                vec[v] = m;
                break;
            }
            else if (w > k)
            {
                jj = v - 1;
            }
            else
            {
                assert(false);
                ii = v;
            }
        }
        assert(ii == 0);
        sort(vec.begin(), vec.end());
        for (auto &&k : vec)
        {
            cout << k << " ";
        }
        cout << endl;
        for (int k = 1; k <= n; k++)
        {
            if (ans[k] == '\0')
            {
                cout << "?";
            }
            cout << ans[k];
        }
        cout << endl;
    }
    ans[n + 1] = '\0';
    printf("! %s\n", ans + 1);
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }

    return 0;
}