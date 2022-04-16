#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
char arr[50][51];
int direct[4][2] = { -1, 0, 0, -1, 1, 0, 0, 1 };
int visited[51][51] = { 0 };
int dp[51][51] = { 0 };

int dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return 0;
	if (arr[y][x] == 'H') return 0;
	if (visited[y][x]) {
		cout << -1;
		exit(0);
	}
	if (dp[y][x]) return dp[y][x];
	visited[y][x] = 1;
	int num = 0;
	for (int i = 0; i < 4; i++) {
		int iny = y + direct[i][0] * (arr[y][x] - '0');
		int inx = x + direct[i][1] * (arr[y][x] - '0');
		num = max(num, dfs(iny, inx) + 1);
	}
	dp[y][x] = num;
	visited[y][x] = 0;
	return num;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << dfs(0, 0);
	return 0;
}