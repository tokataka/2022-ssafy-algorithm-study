#include <iostream>
#include <queue>
using namespace std;

int N, M;
int MAP[50][50];
int visited[50][50];
int unionfind[50][50];
int Area;
int MaxArea = -21e8;

struct Node {
	int row;
	int col;
};

void input() {
	cin >> N >> M;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			cin >> MAP[y][x];
		}
	}
}

int dr[4] = { 0,-1,0,1 };
int dc[4] = { -1,0,1,0 };
int bi[4];
void binary(int A) {
	bi[0] = A % 2;
	bi[1] = (A / 2) % 2;
	bi[2] = ((A / 2) / 2) % 2;
	bi[3] = ((A / 2) / 2) / 2;
}

int tmp = 1;
void bfs(int y, int x) {
	queue <Node> q;
	q.push({ y,x });
	visited[y][x] = -1;
	Area = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		int A = MAP[now.row][now.col];
		binary(A);
		Area++;
		for (int i = 0; i < 4; i++) {
			int nr = dr[i] + now.row;
			int nc = dc[i] + now.col;
			if (nr < 0 || nc < 0 || nr >= M || nc >= N) { continue; }
			if (bi[i] == 1) { continue; }
			if (visited[nr][nc] != 0) { continue; }
			visited[nr][nc] = -1;
			q.push({ nr,nc });
		}
	}
	if (MaxArea < Area) { MaxArea = Area; }
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == -1) { 
				unionfind[y][x] = tmp;
				visited[y][x] = Area;
			}
		}
	}
	tmp++;
}

int main()
{
	input();

	int cnt = 0;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] != 0) { continue; }
			bfs(y, x);
			cnt++;
		}
	}

	int MaxSum = -21e8;
	int Sum=0;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			Sum = 0;
			for (int i = 0; i < 4; i++) {
				int nr = dr[i] + y;
				int nc = dc[i] + x;
				if (nr < 0 || nc < 0 || nr >= M || nc >= N) { continue; }
				if (unionfind[y][x] == unionfind[nr][nc]) { continue; }
				Sum = visited[y][x] + visited[nr][nc];
				if (MaxSum < Sum) { MaxSum = Sum; }
			}
		}
	}

	cout << cnt << "\n" << MaxArea << "\n" << MaxSum;
	return 0;
}