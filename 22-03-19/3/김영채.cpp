#include <iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M;
int arr[51][51];
int used[51][51] = { 0 };
struct Edge {
	int row;
	int col;
};

int bfs(int y, int x) {
	int size = 0;
	queue<Edge> q;
	q.push({ y, x });
	used[y][x] = 1;
	size++;
	while (!q.empty()) {
		Edge now = q.front();
		q.pop();
		int direct[4][2] = { 0, -1, -1, 0, 0, 1, 1, 0 };
		for (int i = 0; i < 4; i++) {
			int iny = now.row + direct[i][0];
			int inx = now.col + direct[i][1];
			if (iny < 0 || inx < 0 || iny >= M || inx >= N) continue;
			if (used[iny][inx]) continue;
			if ((1 << i) & arr[now.row][now.col]) continue;
			size++;
			used[iny][inx] = 1;
			q.push({ iny, inx });
		}
	}
	return size;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	int cnt = 0;
	int maxsize = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!used[i][j]) {
				int val = bfs(i, j);
				if (val >= maxsize) maxsize = val;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	cout << maxsize << endl;

	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			for (int i = 0; i < 4; i++) {
				int val = 1 << i;
				if (val & arr[y][x]) {
					memset(used, 0, sizeof(used));
					arr[y][x] = arr[y][x] - val;
					int change = bfs(y, x);
					if (change > maxsize) maxsize = change;
					arr[y][x] = arr[y][x] + val;
				}		
			}
		}
	}
	cout << maxsize << endl;
	return 0;
}