#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<limits.h>
#include<cmath>

using namespace std;

int N;
int cnt = 0;
int laboratory[51][51];
vector<pair<int, int> >virus;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
bool visited[51][51];

int bfs(queue<pair<pair<int, int>, int >> q) {
    int safe = cnt;
    while (!q.empty()) {
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int ctime = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];
            if (nr < 0 || N <= nr || nc < 0 || N <= nc) continue;
            if (visited[nr][nc] || laboratory[nr][nc] == 1) continue;
            if (laboratory[nr][nc] == 0) {
                --safe;
                if (safe == 0) return ctime + 1;
            }
            visited[nr][nc] = true;
            q.push({ {nr, nc}, ctime + 1 });
        }
    }
    return INT_MAX;
}

int main() {
    int M;
    scanf("%d %d", &N, &M);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            scanf("%d", &laboratory[r][c]);
            if (laboratory[r][c] == 2) virus.push_back(make_pair(r, c));
            else if (laboratory[r][c] == 0) ++cnt;
        }
    }
    int answer = INT_MAX;
    if (cnt == 0) {
        answer = 0;
    }
    else {
        vector<int>ind;
        for (int i = 0; i < virus.size() - M; ++i) ind.push_back(0);
        for (int i = 0; i < M; ++i) ind.push_back(1);
        int route[10];
        for (int i = 0; i < virus.size(); ++i) route[i] = i;
        do {
            queue<pair<pair<int, int>, int>> q;
            memset(visited, 0, sizeof(visited));
            for (int i = 0; i < virus.size(); ++i) {
                if (ind[i] == 1) {
                    q.push({ virus[i], 0 });
                    visited[virus[i].first][virus[i].second] = true;
                }
            }
            int result = bfs(q);
            answer = min(result, answer);
        } while (next_permutation(ind.begin(), ind.end());
        if (answer == INT_MAX) answer = -1;
    }
    printf("%d", answer);
}