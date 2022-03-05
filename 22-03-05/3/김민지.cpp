// https://www.acmicpc.net/problem/24513

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

struct Status {
	int r, c, virus, level;
};

int map[1000][1000];
int levels[1000][1000];
int first, second, third, N, M;
queue<Status>q;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void solve() {
	int counter = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; ++i) {
			int cr = q.front().r;
			int cc = q.front().c;
			int cv = q.front().virus;
			int clevel = q.front().level;
			q.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nr = cr + dr[dir];
				int nc = cc + dc[dir];
				if (nr < 0 || N <= nr || nc < 0 || M <= nc) continue;
				if (map[nr][nc] != 0) continue;
				if (cv == 2) {
					if (map[nr][nc] == 0) {
						map[nr][nc] = 2;
						q.push({ nr,nc,2,clevel + 1 });
						levels[nr][nc] = clevel + 1;
						++second;
					} else if (map[nr][nc] == 1 && levels[nr][nc] == clevel + 1) {
						++third;
						--second;
						map[nr][nc] = 3;
					}
				} else if (cv == 1) {
					if (map[nr][nc] == 0) {
						map[nr][nc] = 1;
						++first;
						levels[nr][nc] = clevel + 1;
						q.push({ nr,nc,1,clevel + 1 });
					} else if (map[nr][nc] == 2 && levels[nr][nc] == clevel + 1) {
						++third;
						--first;
						map[nr][nc] = 3;
					}
				}
			}
		}
	}
}

void init() {
	first = 0;
	second = 0;
	third = 0;
	N = 0;
	M = 0;
	scanf("%d %d", &N, &M);
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < M; ++c) {
			scanf("%d", &map[r][c]);
			if (map[r][c] == 1) {
				q.push({ r,c,1,1 });
				levels[r][c] = 1;
				++first;
			}
			else if(map[r][c] == 2) {
				q.push({ r,c,2,1 });
				levels[r][c] = 2;
				++second;
			}
		}
	}
}

int main() {
	init();
	solve();
	printf("%d %d %d", first, second, third);
}