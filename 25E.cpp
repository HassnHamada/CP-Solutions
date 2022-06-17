#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10, M = 20, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;
char aaa[N], bbb[N], ccc[N], str[N << 1];

int newL(int i, int c, vector<int> &v)
{
    while (i && str[i] != c)
    {
        i = v[i - 1];
    }
    return i + (int)(str[i] == c);
}

pair<int, int> computeF()
{
    int mx = 0;
    vector<int> v;
    v.push_back(0);
    for (int i = 1; str[i]; i++)
    {
        v.push_back(newL(v.back(), str[i], v));
        mx = max(mx, v.back());
    }
    return {v.back(), mx};
}

void run()
{
    scanf("%s%s%s", aaa, bbb, ccc);
    int a = strlen(aaa), b = strlen(bbb), c = strlen(ccc);
    strcpy(str, aaa);
    str[a] = '$';
    strcpy(str + a + 1, bbb);
    auto ba = computeF();
    strcpy(str + a + 1, ccc);
    auto ca = computeF();
    strcpy(str, bbb);
    str[b] = '$';
    strcpy(str + b + 1, aaa);
    auto ab = computeF();
    strcpy(str + b + 1, ccc);
    auto cb = computeF();
    strcpy(str, ccc);
    str[c] = '$';
    strcpy(str + c + 1, aaa);
    auto ac = computeF();
    strcpy(str + c + 1, bbb);
    auto bc = computeF();
    // cout << a + b + c << endl;
    // cout << "ab " << ab.first << endl;
    // cout << "ac " << ac.first << endl;
    // cout << "ba " << ba.first << endl;
    // cout << "bc " << bc.first << endl;
    // cout << "ca " << ca.first << endl;
    // cout << "cb " << cb.first << endl;
    int ans = INF;
    ans = min(ans, a + b + c - ab.first - bc.first);
    ans = min(ans, a + b + c - ac.first - cb.first);
    ans = min(ans, a + b + c - ba.first - ac.first);
    ans = min(ans, a + b + c - bc.first - ca.first);
    ans = min(ans, a + b + c - ca.first - ab.first);
    ans = min(ans, a + b + c - cb.first - ba.first);
    if (ab.second == b)
    {
        ans = min(ans, a + c - max(ac.first, ca.first));
        if (ac.second == c)
        {
            ans = min(ans, a);
        }
        if (ca.second == a)
        {
            ans = min(ans, c);
        }
    }
    if (ac.second == c)
    {
        ans = min(ans, a + b - max(ab.first, ba.first));
        if (ab.second == b)
        {
            ans = min(ans, a);
        }
        if (ba.second == a)
        {
            ans = min(ans, b);
        }
    }
    if (ba.second == a)
    {
        ans = min(ans, b + c - max(bc.first, cb.first));
        if (bc.second == c)
        {
            ans = min(ans, b);
        }
        if (cb.second == b)
        {
            ans = min(ans, c);
        }
    }
    if (bc.second == c)
    {
        ans = min(ans, b + a - max(ba.first, ba.first));
        if (ba.second == a)
        {
            ans = min(ans, b);
        }
        if (ab.second == b)
        {
            ans = min(ans, a);
        }
    }
    if (ca.second == a)
    {
        ans = min(ans, c + b - max(cb.first, bc.first));
        if (cb.second == b)
        {
            ans = min(ans, c);
        }
        if (bc.second == c)
        {
            ans = min(ans, b);
        }
    }
    if (cb.second == b)
    {
        ans = min(ans, c + a - max(ca.first, ac.first));
        if (ca.second == a)
        {
            ans = min(ans, c);
        }
        if (ac.second == c)
        {
            ans = min(ans, a);
        }
    }
    printf("%d\n", ans);
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
