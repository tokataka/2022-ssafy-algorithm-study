#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, students;
char map[6][6];
vector<pair<int, int>>teachers;
vector<pair<int, int>>obs;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

bool solve(vector<int>select) {
	queue<pair<int, int>>q;
	bool visited[6][6];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			visited[i][j] = false;
		}
	}
	for (int i = 0; i < select.size(); ++i) {
		if (select[i] == 1) visited[obs[i].first][obs[i].second] = true;
	}
	for (int i = 0; i < teachers.size(); ++i) {
		int cr = teachers[i].first;
		int cc = teachers[i].second;

		for (int dir = 0; dir < 4; ++dir) {
			int nr = cr;
			int nc = cc;
			while (true) {
				nr += dr[dir];
				nc += dc[dir];
				if (nr < 0 || N <= nr || nc < 0 || N <= nc) break;
				if (visited[nr][nc]) break;
				if (map[nr][nc] == 'S') return false;
			}
		}
	}
	return true;
}

int main() {
	scanf("%d", &N);
	int cnt = 0;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cin >> map[r][c];
			if (map[r][c] == 'X') {
				obs.push_back(make_pair(r, c));
				++cnt;
			} else if (map[r][c] == 'T') {
				teachers.push_back(make_pair(r, c));
			}
		}
	}
	vector<int>select;
	for (int i = 0; i < cnt - 3; ++i) select.push_back(0);
	for (int i = 0; i < 3; ++i) select.push_back(1);
	do {
		bool result = solve(select);
		if (result) {
			cout << "YES";
			return 0;
		}
	} while (next_permutation(select.begin(), select.end()));
	cout << "NO";
}