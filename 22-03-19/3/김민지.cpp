#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<queue>

using namespace std;

int C, R, idx;
int castle[50][50];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int visited[50][50];
int sizes[2500];

void dfs(int r, int c) {
	++sizes[idx];
	visited[r][c] = idx;
	int walls = castle[r][c];
	if (8 > walls && visited[r + 1][c] == 0) dfs(r + 1, c);
	else if (walls >= 8) walls -= 8;

	if (4 > walls && visited[r][c + 1] == 0) dfs(r, c + 1);
	else if (walls >= 4) walls -= 4;
	
	if (2 > walls && visited[r - 1][c] == 0) dfs(r - 1, c);
	else if (walls >= 2) walls -= 2;

	if (walls == 0 && visited[r][c - 1] == 0) dfs(r, c - 1);
}


int main() {
	scanf("%d %d", &C, &R);
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			scanf("%d", &castle[r][c]);
		}
	}
	int roomMax = -1;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (visited[r][c] == 0) {
				++idx;
				dfs(r, c);
				roomMax = max(roomMax, sizes[idx]);
			}
		}
	}
	int broken = -1;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			int room = visited[r][c];
			for (int dir = 0; dir < 4; ++dir) {
				int nr = r + dr[dir];
				int nc = c + dc[dir];
				if (nr < 0 || R <= nr || nc < 0 || C <= nc) continue;
				int nextRoom = visited[nr][nc];
				if (room == nextRoom) continue;
				if (broken >= sizes[room] + sizes[nextRoom]) continue;
				broken = sizes[room] + sizes[nextRoom];
			}
		}
	}
	printf("%d\n%d\n%d\n", idx, roomMax, broken);
}