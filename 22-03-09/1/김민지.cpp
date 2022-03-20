//#define _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//#include<stdio.h>
//#include<queue>
//
//using namespace std;
//
//int map[50][50];
//int dp[50][50];
//
//struct Status {
//	int r, c, trash, near;
//};
//
//struct cmp {
//	bool operator()(Status s1, Status s2) {
//		if (s1.trash == s2.trash) {
//			return s1.near > s2.near;
//		}
//		return s1.trash > s2.trash; // increasing order
//	}
//};
//
//int main() {
//	int R, C;
//	int sr = 0;
//	int sc = 0;
//	int er = 0;
//	int ec = 0;
//	scanf("%d %d", &R, &C);
//	int dr[4] = { -1,1,0,0 };
//	int dc[4] = { 0,0,-1,1 };
//	for (int r = 0; r < R; ++r) {
//		string s;
//		cin >> s;
//		for (int c = 0; c < C; ++c) {
//			dp[r][c] = -1;
//			char target = s[c];
//			if (target == 'F') {
//				er = r;
//				ec = c;
//			}
//			else if (target == 'S') {
//				sr = r;
//				sc = c;
//			}
//			else if (target == 'g') {
//				map[r][c] = 2;
//				for (int dir = 0; dir < 4; ++dir) {
//					int nr = r + dr[dir];
//					int nc = c + dc[dir];
//					if (nr < 0 || R <= nr || nc < 0 || C <= nc) continue;
//					if (map[nr][nc] == 2) continue;
//					map[nr][nc] = 1;
//				}
//			}
//		}
//	}
//	map[sr][sc] = 0;
//	map[er][ec] = 0;
//	priority_queue<Status, vector<Status>, cmp>pq;
//	pq.push({ sr,sc,0,0 });
//	dp[sr][sc] = 0;
//
//	while (!pq.empty()) {
//		int cr = pq.top().r;
//		int cc = pq.top().c;
//		int ctrash = pq.top().trash;
//		int cnear = pq.top().near;
//		if (cr == er && cc == ec) {
//			cout << ctrash<<" "<<cnear;
//			break;
//		}
//		pq.pop();
//		for (int dir = 0; dir < 4; ++dir) {
//			int nr = cr + dr[dir];
//			int nc = cc + dc[dir];
//			if (nr < 0 || R <= nr || nc < 0 || C <= nc) continue;
//			if (map[nr][nc] == 2) {
//				if (dp[nr][nc] == -1 || dp[nr][nc] > ctrash + 1) {
//					dp[nr][nc] = ctrash + 1;
//					pq.push({ nr,nc,ctrash + 1, cnear });
//				}
//			}
//			else {
//				if (dp[nr][nc] == -1 || dp[nr][nc] > ctrash) {
//					dp[nr][nc] = ctrash;
//					if (map[nr][nc] == 1) pq.push({ nr,nc,ctrash,cnear + 1 });
//					else pq.push({ nr,nc,ctrash,cnear });
//				}
//			}
//		}
//	}
//}