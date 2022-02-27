#include<iostream>
#include<cstdio>
#include<queue>
#include<string.h>
#include<cstring>

using namespace std;

int R, C;
char map[1001][1001];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int visited[2][1001][1001];

int bfs() {
    queue<pair<pair<int, int>, pair<int, int>> > q;
    q.push(make_pair(make_pair(0, 0), make_pair(1, 0)));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < R; ++j) {
            for (int k = 0; k < C; ++k) {
                visited[i][j][k] = 0;
            }
        }
    }
    visited[0][0][0] = true;

    while (!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int ctimes = q.front().second.first;
        if (cr == R - 1 && cc == C - 1) return ctimes;
        int cbroken = q.front().second.second;
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];
            if (nr < 0 || R <= nr || nc < 0 || C <= nc) continue;
            int nbroken = cbroken;
            if (map[nr][nc] == '1') {
                if (nbroken == 1) continue;
                else nbroken = 1;
            }
            if (visited[nbroken][nr][nc]) continue;
            visited[nbroken][nr][nc] = true;
            q.push({ make_pair(nr, nc), make_pair(ctimes + 1, nbroken) });
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &R, &C);
    for (int r = 0; r < R; ++r) {
        string line;
        cin >> line;
        for (int c = 0; c < C; ++c) {
            map[r][c] = line[c];
        }
    }
    printf("%d", bfs());
    return 0;
}