#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <iostream>
#include <iostream>
using namespace std;
typedef long long ll;

void run()
{
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'a' + i)
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("_output.txt", "w", stdout);
    freopen("_input.txt", "r", stdin);
#endif
    int t = 1;
    scanf("%d", &t);
    while (t--)
    {
        run();
    }
    return 0;
}