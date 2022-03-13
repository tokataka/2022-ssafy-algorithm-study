#include<iostream>
#include<vector>
#include<queue>

using namespace std;

char arr[50][50];
int used[50][50] = { 0 };
struct Node {
	int y;
	int x;
	int trash;
	int pass;
};

struct cmp {
	bool operator() (Node right, Node left) {
		if (left.trash < right.trash) return true;
		else if (left.trash > right.trash) return false;
		if (left.pass < right.pass) return true;
		else return false;
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	priority_queue<Node, vector<Node>, cmp> pq;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') pq.push({ i, j, 0, 0 });
		}
	}

	int direct[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'g') {
				for (int k = 0; k < 4; k++) {
					int iny = i + direct[k][0];
					int inx = j + direct[k][1];
					if (iny < 0 || inx < 0 || iny >= N || inx >= M) continue;
					if (arr[iny][inx] == '.') arr[iny][inx] = '_';
				}
			}
		}
	}

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (used[now.y][now.x]) continue;
		used[now.y][now.x] = 1;
		for (int i = 0; i < 4; i++) {
			int pass = now.pass;
			int trash = now.trash;
			int iny = now.y + direct[i][0];
			int inx = now.x + direct[i][1];
			if (iny < 0 || inx < 0 || iny >= N || inx >= M) continue;
			if (arr[iny][inx] == 'F') {
				cout << trash << " " << pass;
				return 0;
			}
			else if (arr[iny][inx] == '_') pass++;
			else if (arr[iny][inx] == 'g') trash++;

			pq.push({ iny, inx, trash, pass });

		}
	}
	return 0;
}