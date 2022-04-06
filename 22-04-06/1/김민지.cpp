#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

int R, C, cnt;
int map[301][301];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
queue<pair<int, int> >q;
bool visited[301][301];

bool check(int r, int c) {
	queue<pair<int, int> >cq;
	memset(visited, 0, sizeof(visited));
	visited[r][c] = true;
	cq.push({ r, c });
	int temp = 0;

	while (!cq.empty()) {
		int cr = cq.front().first;
		int cc = cq.front().second;
		++temp;
		cq.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nr = cr + dr[dir];
			int nc = cc + dc[dir];
			if (nr < 0 || R <= nr || nc < 0 || C <= nc) continue;
			if (visited[nr][nc]) continue;
			if (map[nr][nc] == 0) continue;
			visited[nr][nc] = true;
			cq.push({ nr, nc });
		}
	}
	if (temp != cnt) return true;
	return false;
}

bool melt() {
	int size = q.size();
	int tide = 0;
	for (int i = 0; i < size; ++i) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		q.push({ cr, cc });

		for (int dir = 0; dir < 4; ++dir) {
			int nr = cr + dr[dir];
			int nc = cc + dc[dir];
			if (nr < 0 || R <= nr || nc < 0 || C <= nc) continue;
			if (map[nr][nc] != 0) {
				--map[nr][nc];
				++tide;
				if (map[nr][nc] == 0) {
					q.push({ nr, nc });
					--cnt;
				}
			}
		}
	}
	if (tide == 0) return false;
	return true;
}

int main() {
	scanf("%d %d", &R, &C);
	cnt = 0;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			scanf("%d", &map[r][c]);
			if (map[r][c] == 0) q.push({ r, c });
			else ++cnt;
		}
	}
	int time = 0;
	if (cnt != 0) {
		while (true) {
			++time;
			bool result = melt(); 
			if (!result || cnt == 0) { // nothing melted
				time = 0;
				break;
			}
			bool divided = false;
			for (int r = 0; r < R; ++r) {
				for (int c = 0; c < C; ++c) {
					if (map[r][c] != 0) {
						divided = check(r, c);
						goto NEXT;
					}
				}
			}
		NEXT:
			if (divided) break;
		}
	}
	printf("%d", time);
}