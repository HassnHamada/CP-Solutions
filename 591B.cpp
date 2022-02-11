#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 2e5 + 10;
char str[N];

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen(".\\c++\\_input.txt", "r", stdin);
    // freopen(".\\c++\\_output.txt", "w", stdout);

    vector<char> enc(26), dec(26);
    iota(enc.begin(), enc.end(), 0);
    iota(dec.begin(), dec.end(), 0);
    int n, m;
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%c", str + i);
        str[i] -= 'a';
    }
    for (int i = 0; i < m; i++)
    {
        char a, b;
        scanf("\n%c %c", &a, &b);
        swap(enc[dec[a - 'a']], enc[dec[b - 'a']]);
        swap(dec[a - 'a'], dec[b - 'a']);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%c", enc[str[i]] + 'a');
    }
    printf("\n");
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}