#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int arr[101][101] = { 0 };
int visited[101] = { 0 };

void bfs(int start) {
	visited[start] = 1;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			if (!arr[now][i]) continue;
			visited[i] = visited[now] + 1;
			q.push(i);
		}
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	int result;
	int mini = 99999;
	for (int i = 1; i <= N; i++) {
		bfs(i);
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			sum += visited[j] - 1;
		}
		if (sum < mini) {
			mini = sum;
			result = i;
		}
		memset(visited, 0, sizeof(visited));
	}
	cout << result;
	return 0;
}