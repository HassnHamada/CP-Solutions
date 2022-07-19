#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 2, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
struct Node
{
    int nxt[M];
    int leaf = 0;
    Node()
    {
        memset(nxt, -1, sizeof(nxt));
    }
};
vector<Node> tri;
int arr[N];

void insert(int val)
{
    // cout << val << endl;
    vector<int> tem;
    for (int i = 0; val >> i; i++)
    {

        int c = (val >> i) & 1;
        tem.push_back(c);
    }
    int v = 0;
    while (!tem.empty())
    {
        int c = tem.back();
        tem.pop_back();
        if (tri[v].nxt[c] == -1)
        {
            tri[v].nxt[c] = tri.size();
            tri.emplace_back();
        }
        v = tri[v].nxt[c];
    }
    tri[v].leaf += 1;
}

bool match(int val)
{
    // cout << val << endl;
    vector<int> stk, tem;
    int v = 0;
    for (int i = 0; val >> i; i++)
    {

        int c = (val >> i) & 1;
        tem.push_back(c);
    }
    while (!tem.empty())
    {
        int c = tem.back();
        tem.pop_back();
        // cout << v << " ";
        if (tri[v].nxt[c] == -1)
        {
            // cout << "dsasd";
            return false;
        }
        stk.push_back(v);
        v = tri[v].nxt[c];
    }
    while (tri[v].leaf == 0)
    {
        stk.push_back(v);
        if (tri[v].nxt[0] == -1)
        {
            v = tri[v].nxt[1];
        }
        else
        {
            v = tri[v].nxt[0];
        }
        assert(v != -1);
    }
    tri[v].leaf -= 1;
    // cout << val << " " << v << endl;
    if (tri[v].leaf == 0 && tri[v].nxt[0] == -1 && tri[v].nxt[1] == -1)
    {
        int p = stk.back();
        // assert(tri[p].nxt[0] != -1 || tri[p].nxt[1] != -1);
        while (true)
        {
            // cout << p << " ";
            if (tri[p].nxt[0] == v)
            {
                tri[p].nxt[0] = -1;
                if (tri[p].nxt[1] != -1 || tri[p].leaf)
                {
                    break;
                }
            }
            else
            {
                assert(tri[p].nxt[1] == v);
                tri[p].nxt[1] = -1;
                if (tri[p].nxt[0] != -1 || tri[p].leaf)
                {
                    break;
                }
            }
            // tri[p].nxt[0] = tri[p].nxt[1] = -1;
            stk.pop_back();
            if (stk.empty())
            {
                break;
            }
            v = p;
            p = stk.back();
        }
        // if (tri[p].nxt[0] == v)
        // {
        //     tri[p].nxt[0] = -1;
        // }
        // else
        // {
        //     assert(tri[p].nxt[1] == -1 || tri[p].nxt[1] == v);
        //     tri[p].nxt[1] = -1;
        // }
    }
    return true;
}

void run()
{
    tri.clear();
    tri.emplace_back();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
        while (arr[i] % 2 == 0)
        {
            arr[i] >>= 1;
        }
    }
    sort(arr, arr + n, greater<int>());
    for (int i = 0, v; i < n; i++)
    {
        scanf("%d", &v);
        while (v % 2 == 0)
        {
            v >>= 1;
        }
        insert(v);
        // for (auto &&j : tri)
        // {
        //     cout << j.leaf << endl;
        // }
        // cout << endl;
    }
    // cout << tri[1].leaf << endl;
    // cout << tri[2].leaf << endl;
    // cout << tri[3].leaf << endl;
    // cout << tri[4].leaf << endl;
    // cout << tri[5].leaf << endl;
    // match(arr[0]);
    // cout << tri[1].leaf << endl;
    // cout << tri[2].leaf << endl;
    // cout << tri[3].leaf << endl;
    // cout << tri[4].leaf << endl;
    // cout << tri[5].leaf << endl;
    // match(arr[1]);
    // cout << tri[1].leaf << endl;
    // cout << tri[2].leaf << endl;
    // cout << tri[3].leaf << endl;
    // cout << tri[4].leaf << endl;
    // cout << tri[5].leaf << endl;
    // match(arr[2]);
    // cout << tri[1].leaf << endl;
    // cout << tri[2].leaf << endl;
    // cout << tri[3].leaf << endl;
    // cout << tri[4].leaf << endl;
    // cout << tri[5].leaf << endl;
    bool ok = true;
    for (int i = 0; ok && i < n; i++)
    {
        ok = match(arr[i]);
        // cout << arr[i] << " " << match(arr[i]) << "\n";
        // for (auto &&j : tri)
        // {
        //     cout << j.leaf << endl;
        // }
        // cout << endl;
    }
    // cout << endl;
    printf(ok ? "YES\n" : "NO\n");
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}