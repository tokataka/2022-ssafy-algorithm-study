#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int MAP[50][50];
int N;
int M;
int cnt1;

struct virus {
	int row;
	int col;
};

vector <virus> V;

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> MAP[y][x];
			if (MAP[y][x] == 2) {
				V.push_back({ y,x });
			}
			else if (MAP[y][x] == 1) { cnt1++; }
		}
	}
}

int Time;
virus path[11];
int visited[50][50];
int minnum = 21e8;

void bfs() {
	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };
	queue<virus> q;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			visited[y][x] = 0;
		}
	}

	for (int i = 0; i < M; i++) {
		q.push({ path[i].row, path[i].col });
		visited[path[i].row][path[i].col] = 1;
	}

	while (!q.empty()) {
		virus now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = dr[i] + now.row;
			int nc = dc[i] + now.col;
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) { continue; }
			if (visited[nr][nc] != 0) { continue; }
			if (MAP[nr][nc] == 1) { continue;}
			//if(MAP[nr][nc]==2){}
			visited[nr][nc] = visited[now.row][now.col]+1;
			q.push({ nr,nc });
		}
	}
	Time = 0;
	int flag = 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (MAP[y][x] == 0) {
				if (visited[y][x] == 0) {
					flag = 0;
					break;
				}
				else {
					Time = max(Time, visited[y][x]);
				}
			}
		}
	}
	if (flag) { minnum = min(minnum, Time); }
}

int check() {
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == 0) { cnt++; }
		}
	}
	if (cnt == cnt1) { return 1; }
	else if (cnt > cnt1) { return 0; }
}


void dfs(int level, int prev) {
	if (level == M) {
		bfs();
		return;
	}

	for (int i = prev+1; i < V.size(); i++) {
		path[level] = V[i];
		dfs(level + 1, i);
		path[level] = { 0, 0};
	}
}

int main()
{
	input();
	int de = 0;
	dfs(0, -1);

	if (minnum == 21e8) { cout << -1; }
	else if (minnum == 0) { cout << 0; }
	else { cout << minnum-1; }
	return 0;
}