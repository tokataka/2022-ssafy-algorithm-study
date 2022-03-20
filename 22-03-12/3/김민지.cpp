//#include<iostream>
//#include<stdio.h>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//int mini = 20e8;
//
//void solve(int x, int cnt) {
//	if (x == 1) {
//		if (mini > cnt) mini = cnt;
//		return;
//	}
//	if (cnt >= mini) return;
//	if (x % 3 == 0) {
//		int next = x / 3;
//		solve(next, cnt + 1);
//	}
//	if (x % 2 == 0) {
//		int next = x / 2;
//		solve(next, cnt + 1);
//	}
//	solve(x - 1, cnt + 1);
//}
//
//int main() {
//	int x;
//	cin >> x;
//	solve(x, 0);
//	cout << mini;
//}