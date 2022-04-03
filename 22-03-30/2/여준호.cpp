#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int MAP[105][105];
int cnt;
vector <int> space;

struct Node {
	int row;
	int col;
};

void rect(int x1, int y1, int x2, int y2) {
	for (int y = y1; y < y2; y++) {
		for (int x = x1; x < x2; x++) {
			MAP[y][x] = -1;
		}
	}
}

void bfs(int y, int x) {
	queue <Node> q;
	q.push({ y,x });
	MAP[y][x] = 1;

	int dr[4] = { -1,1,0,0 };
	int dc[4] = { 0,0,-1,1 };
	int area = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = dr[i] + now.row;
			int nc = dc[i] + now.col;
			if (nr < 0 || nc < 0 || nr >= M || nc >= N) { continue; }
			if (MAP[nr][nc] == -1) continue;
			if (MAP[nr][nc] == 1) continue;
			MAP[nr][nc] = 1;
			area += 1;
			q.push({ nr,nc });
		}
	}
	space.push_back(area);
}

int main()
{
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		rect(x1, y1, x2, y2);
	}

	int dde = 0;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (MAP[y][x] == -1) { continue; }
			if (MAP[y][x] == 1) { continue; }
			bfs(y, x);
			cnt++;
		}
	}

	cout << cnt << "\n";
	sort(space.begin(), space.end());
	for (int i = 0; i < space.size(); i++) {
		cout << space[i] << " ";
	}

	return 0;
}