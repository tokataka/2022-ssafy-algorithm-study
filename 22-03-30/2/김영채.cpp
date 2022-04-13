#include <iostream>
#include<algorithm>

using namespace std;

int N, M, K;
int arr[100][100] = { 0 };
int visited[100][100] = { 0 };
int area[100] = { 0 };
int direct[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };
int cnt = 0;

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int iny = y + direct[i][0];
		int inx = x + direct[i][1];
		if (iny < 0 || inx < 0 || iny >= N || inx >= M) continue;
		if (visited[iny][inx]) continue;
		if (arr[iny][inx]) continue;
		visited[iny][inx] = 1;
		area[cnt]++;
		dfs(iny, inx);
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int y1, x1, y2, x2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				arr[y][x] = 1;
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (arr[y][x]) continue;
			if (visited[y][x]) continue;
			visited[y][x] = 1;
			area[cnt]++;
			dfs(y, x);
			cnt++;
		}
	}
	cout << cnt << endl;
	sort(area, area+cnt);
	for (int i = 0; i < cnt; i++) {
		cout << area[i] << " ";
	}
	return 0;
}