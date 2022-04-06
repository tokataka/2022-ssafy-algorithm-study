#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int MAP[305][305];
int N, M;
int used[305][305];

struct Node {
	int row;
	int col;
};

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> MAP[y][x];
		}
	}
}

void melt() {

	int tmp[305][305] = { 0 };
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (MAP[y][x] == 0)continue;
			int dr[4] = { -1,1,0,0 };
			int dc[4] = { 0,0,-1,1 };
			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int nr = y + dr[i];
				int nc = x + dc[i];
				if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
				if (MAP[nr][nc] == 0) cnt++;
			}
			int n = MAP[y][x] - cnt;
			if (n < 0) tmp[y][x] = 0;
			else tmp[y][x] = n;
		}
	}
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			MAP[y][x] = tmp[y][x];
		}
	}
}

void bfs(int y, int x) {
	queue <Node> q;
	q.push({ y,x });
	used[y][x] = 1;

	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = now.row + dr[i];
			int nc = now.col + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) { continue; }
			if (used[nr][nc] != 0) { continue; }
			if (MAP[nr][nc] == 0) { continue; }
			used[nr][nc] = 1;
			q.push({ nr,nc });
		}
	}
}

void init() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			used[y][x] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	int year = 0;
	while (1)
	{
		melt();
		int cnt = 0;
		init();
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (MAP[y][x] == 0) continue;
				if (used[y][x] == 1)continue;
				bfs(y, x);
				cnt++;
			}
		}
		year++;
		if (cnt >= 2) {
			cout << year;
			break;
		}
		else if (cnt == 0) {
			cout << 0;
			break;
		}
		
	}

	return 0;
}