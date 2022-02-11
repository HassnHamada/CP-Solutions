#include <bits/stdc++.h>
// #include <chrono>
using namespace std;
// using namespace std::chrono;
// typedef long long int ll;

const int N = 12;
const pair<int, int> targets[] = {{3, 3}, {3, 10}, {10, 3}, {10, 10}},
                     blocks[] = {{6, 6}, {6, 7}, {7, 6}, {7, 7}, {9, 2}, {9, 3}, {10, 2}, {9, 10}, {9, 11}, {10, 11}};
int dis[N + 1][N + 1];

bool inBlocks(pair<int, int> pos)
{
    return any_of(blocks, blocks + 10, [&pos](pair<int, int> block)
                  { return block == pos; });
}

bool inTargets(pair<int, int> pos)
{
    return any_of(targets, targets + 4, [&pos](pair<int, int> target)
                  { return target == pos; });
}

void posMoves(pair<int, int> pos, vector<pair<int, int>> &in)
{
    if (pos.first != 1 && !inBlocks({pos.first - 1, pos.second}))
    {
        in.push_back({pos.first - 1, pos.second});
    }
    if (pos.first != N && !inBlocks({pos.first + 1, pos.second}))
    {
        in.push_back({pos.first + 1, pos.second});
    }
    if (pos.second != 1 && !inBlocks({pos.first, pos.second - 1}))
    {
        in.push_back({pos.first, pos.second - 1});
    }
    if (pos.second != N && !inBlocks({pos.first, pos.second + 1}))
    {
        in.push_back({pos.first, pos.second + 1});
    }
}

int minDis(pair<int, int> pos)
{
    return dis[pos.first][pos.second];
}

bool comp(pair<int, int> pos1, pair<int, int> pos2)
{
    if (minDis(pos1) <= minDis(pos2))
    {
        return true;
    }
    return false;
}

char getDir(pair<int, int> oldPos, pair<int, int> newPos)
{
    if (oldPos.first + 1 == newPos.first)
    {
        return 'D';
    }
    if (oldPos.first - 1 == newPos.first)
    {
        return 'U';
    }
    if (oldPos.second + 1 == newPos.second)
    {
        return 'R';
    }
    if (oldPos.second - 1 == newPos.second)
    {
        return 'L';
    }
    assert(false);
    return '\0';
}

void greedy(pair<int, int> pos, string &ans)
{
    if (inTargets(pos))
    {
        printf("%d\n", ans.size());
        return;
    }
    vector<pair<int, int>> movesVec;
    posMoves(pos, movesVec);
    sort(movesVec.begin(), movesVec.end(), comp);
    ans.push_back(getDir(pos, movesVec[0]));
    greedy(movesVec[0], ans);
}

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < 4; i++)
    {
        q.push(targets[i]);
    }
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        vector<pair<int, int>> moves;
        posMoves(pos, moves);
        for (auto &&i : moves)
        {
            if (dis[i.first][i.second] || inTargets(i))
            {
                continue;
            }
            dis[i.first][i.second] = dis[pos.first][pos.second] + 1;
            q.push(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    // auto start = high_resolution_clock::now();
    // freopen("_input.txt", "r", stdin);
    // freopen("_output.txt", "w", stdout);

    bfs();
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //     {
    //         if (inBlocks({i, j}))
    //         {
    //             continue;
    //         }
    //         printf("%d %d\n", i, j);
    //         string ans;
    //         greedy({i, j}, ans);
    //         printf("%s\n--------------\n", ans.c_str());
    //     }
    // }

    int l;
    cin >> l;
    while (l--)
    {
        int r, c;
        cin >> r >> c;
        string ans;
        greedy({r, c}, ans);
        printf("%s\n", ans.c_str());
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}