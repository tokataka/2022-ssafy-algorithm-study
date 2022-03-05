#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

int R, C;
char map[51][51];
bool wv[51][51];
bool hv[51][51];
queue<pair<int, int> >wq;
queue<pair<int, int> >hq;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

bool bfs() {
    int ws = wq.size();
    for (int i = 0; i < ws; ++i) {
        int cwr = wq.front().first;
        int cwc = wq.front().second;
        wq.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nwr = cwr + dr[dir];
            int nwc = cwc + dc[dir];
            if (nwr < 0 || R <= nwr || nwc < 0 || C <= nwc) continue;
            if (wv[nwr][nwc]) continue;
            if (map[nwr][nwc] == 'D' || map[nwr][nwc] == 'X') continue;
            wv[nwr][nwc] = true;
            wq.push({ nwr, nwc });
        }
    }

    int hs = hq.size();
    for (int i = 0; i < hs; ++i) {
        int chr = hq.front().first;
        int chc = hq.front().second;
        hq.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nhr = chr + dr[dir];
            int nhc = chc + dc[dir];

            if (nhr < 0 || R <= nhr || nhc < 0 || C <= nhc) continue;
            if (map[nhr][nhc] == 'D') return true;
            else if (map[nhr][nhc] == 'X') continue;
            if (wv[nhr][nhc] || hv[nhr][nhc]) continue;
            hv[nhr][nhc] = true;
            hq.push({ nhr, nhc });
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &R, &C);
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> map[r][c];
            if (map[r][c] == 'S') {
                hq.push({ r, c });
                hv[r][c] = true;
            }
            else if (map[r][c] == '*') {
                wq.push({ r, c });
                wv[r][c] = true;
            }
        }
    }
    int time = 0;
    while (true) {
        ++time;
        bool result = bfs();
        if (result || hq.size() == 0) {
            if (result) cout << time;
            else cout << "KAKTUS";
            break;
        }
    }
    return 0;
}