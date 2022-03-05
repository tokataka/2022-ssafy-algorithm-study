#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char arr[50][51];

struct Node {
	int row;
	int col;
};

int main()
{
	//입력 및 위치저장
	int R, C;
	cin >> R >> C;
	int sr, sc, er, ec;
	int used[50][50] = { 0 };
	queue <Node> w;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'S') {
				sr = i;
				sc = j;
			}
			if (arr[i][j] == 'D') {
				er = i;
				ec = j;
			}
			if (arr[i][j] == '*') {
				w.push({ i,j });
				used[i][j] = -1;
			}
		}
	}

	//bfs
	queue <Node> q;
	q.push({ sr,sc });
	used[sr][sc] = 1;

	while (!q.empty()) {
		int a = w.size();
		while (a--) {
			Node now = w.front();
			w.pop();

			int dy[4] = { -1,1,0,0 };
			int dx[4] = { 0,0,-1,1 };
			for (int i = 0; i < 4; i++) {
				int ny = now.row + dy[i];
				int nx = now.col + dx[i];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) { continue; }
				if (used[ny][nx] != 0) { continue; }
				if (arr[ny][nx] == 'X' || arr[ny][nx] == 'D') { continue; }
				used[ny][nx] = -1;
				arr[ny][nx] = '*';
				w.push({ ny,nx });
			}
		}
		int b = q.size();
		while (b--) {
			Node now = q.front();
			q.pop();

			int dy[4] = { -1,1,0,0 };
			int dx[4] = { 0,0,-1,1 };
			for (int i = 0; i < 4; i++) {
				int ny = now.row + dy[i];
				int nx = now.col + dx[i];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) { continue; }
				if (used[ny][nx] != 0) { continue; }
				if (arr[ny][nx] == 'X' || arr[ny][nx] == '*') { continue; }

				used[ny][nx] = used[now.row][now.col] + 1;
				q.push({ ny,nx });
			}
		}
		if (used[er][ec] != 0) { break; }
	}

	if (used[er][ec] == 0) { cout << "KAKTUS"; }
	else cout << used[er][ec] - 1;

	return 0;
}