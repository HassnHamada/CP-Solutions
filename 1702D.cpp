#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10, M = 26, L = 10, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

// map<int, int> fff, lll;
char str[N];
vector<int> vec[M];

void run()
{
    scanf("%s", str);
    int n = strlen(str), p, c = 0;
    scanf("%d", &p);
    for (int i = 0; i < n; i++)
    {
        vec[str[i] - 'a'].push_back(i);
        c += str[i] - 'a' + 1;
    }
    for (int i = M - 1; ~i && c > p; i--)
    {
        while (c > p && !vec[i].empty())
        {
            str[vec[i].back()] = '!';
            vec[i].pop_back();
            c -= i + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '!')
        {
            continue;
        }
        printf("%c", str[i]);
    }
    printf("\n");
    for (int i = 0; i < M; i++)
    {
        vec[i].clear();
    }
}

int main()
{
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while (t--)
    // while (scanf("%d", &n), n)
    {
        run();
    }
    return 0;
}
