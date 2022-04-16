#include<iostream>

using namespace std;

int N, M;
int arr[500][500];
int visited[500][500] = { 0 };
int direct[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int sum = 0;
int maxi = -99999;

void dfs(int y, int x, int level, int sum) {
	if (level == 4) {
		if (sum > maxi) maxi = sum;
		return;
	}
	sum += arr[y][x];
	for (int i = 0; i < 4; i++) {
		int iny = y + direct[i][0];
		int inx = x + direct[i][1];
		if (iny < 0 || inx < 0 || iny >= N || inx >= M) continue;
		if (visited[iny][inx]) continue;
		visited[iny][inx] = 1;
		dfs(iny, inx, level + 1, sum);
		visited[iny][inx] = 0;
	}
}

void other(int y, int x) {
	int sumo = 0;
	if (y - 1 >= 0 && x + 2 < M) {
		sumo += arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 1];
		if (maxi < sumo) maxi = sumo;
	}
	sumo = 0;
	if (y + 1 < N && x + 2 < M) {
		sumo += arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1];
		if (maxi < sumo) maxi = sumo;
	}
	sumo = 0;
	if (y +2 < N && x + 1 < M) {
		sumo += arr[y][x] + arr[y+1][x] + arr[y+2][x] + arr[y+1][x + 1];
		if (maxi < sumo) maxi = sumo;
	}
	sumo = 0;
	if (y+ 1 < N && y-1>=0 && x +1 < M) {
		sumo += arr[y][x] + arr[y][x+1] + arr[y+1][x+1] + arr[y - 1][x + 1];
		if (maxi < sumo) maxi = sumo;
	}
	return;
	
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			visited[y][x] = 1;
			dfs(y, x, 0, 0);
			visited[y][x] = 0;
			other(y, x);
		}
	}
	cout << maxi;
	return 0;
}