#include<iostream>
#include<stdio.h>
#include<unordered_map>
#include<queue>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	if (N == 1) {
		cout << 4;
		return 0;
	}
	unordered_map<int, bool>visited;
	queue<int>q;
	int numbers[4] = { 1,5,10,50 };
	for (int i = 0; i < 4; ++i) { q.push(numbers[i]); }
	int cnt = 1;
	while (!q.empty()) {
		int size = q.size();
		visited.clear();
		++cnt;
		for (int i = 0; i < size; ++i) {
			int cur = q.front();
			q.pop();
			for (int j = 0; j < 4; ++j) {
				int next = cur + numbers[j];
				if (visited.count(next) == 0) {
					visited.insert({ next, true });
					q.push(next);
				}
			}
		}
		if (cnt == N) {
			cout << visited.size();
			break;
		}
	}
	return 0;
}