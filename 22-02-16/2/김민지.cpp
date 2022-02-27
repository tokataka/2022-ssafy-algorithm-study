#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int main() {
	int R, C;
	scanf("%d %d", &R, &C);
	//char map[12][12] = {'.'};
	char map[12][12];
	int melted[12][12] = { 0 };
	memset(map, '.', sizeof(map));
	queue<pair<int, int>>q;
	for (int r = 1; r <= R; ++r) {
		string line;
		cin >> line;
		for (int c = 1; c <= C; ++c) {
			map[r][c] = line[c - 1];
			if (map[r][c] == 'X') {
				q.push(make_pair(r, c));
				//cout << r << "," << c << endl;
			}
		}
	}
	int dr[4] = { -1,1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };
	int size = q.size();
	int maxr = -1;
	int maxc = -1;
	int minr = 13;
	int minc = 13;
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		int count = 0;

		for (int dir = 0; dir < 4; ++dir) {
			int nr = cr + dr[dir];
			int nc = cc + dc[dir];
			if (map[nr][nc] == '.') ++count;
		}
		if (count < 3) {
			maxr = max(maxr, cr);
			maxc = max(maxc, cc);
			minr = min(minr, cr);
			minc = min(minc, cc);
		}
		else {
			melted[cr][cc] = true;
		}
	}
	for (int r = minr; r <= maxr; ++r) {
		for (int c = minc; c <= maxc; ++c) {
			if (map[r][c] == 'X' && !melted[r][c]) {
				cout << 'X';
			}
			else {
				cout << '.';
			}
		}
		cout << endl;
	}


}