#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10, M = 11, MOD = 1e9 + 7, HV = 151, INF = 0x3f3f3f3f;

char str[N];

void run()
{
    scanf("%s", str);
    int n = strlen(str);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            st.push(1);
        }
        else
        {
            int t = st.empty() ? -1 : st.top();
            if (t % 2 == 0 || t == -1)
            {
                st.push(-1);
                continue;
            }
            st.pop();
            while (!st.empty() && t % 2 == 1)
            {
                int v = st.top();
                if (v == -1)
                {
                    break;
                }
                st.pop();
                t += v;
            }
            st.push(t + 1);
        }
    }
    int mx = 0, cnt = 0;
    while (!st.empty())
    {
        int t = st.top();
        st.pop();
        t = t / 2 * 2;
        if (t > mx)
        {
            mx = t;
            cnt = 1;
        }
        else if (t == mx)
        {
            cnt += 1;
        }
    }
    printf("%d %d\n", mx, mx ? cnt : 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
#endif
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}