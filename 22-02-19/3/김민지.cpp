#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	int M;
	scanf("%d", &M);
	vector<vector<int>>family;
	for (int i = 0; i <= N; ++i) {
		vector<int>v;
		family.push_back(v);
	}
	//n1, n2 중 어느 사람이 손윗사람인지 알 수 없음
	//어느쪽으로 시작해도 답을 구할 수 있도록 양방향 그래프로 구현
	for (int i = 0; i < M; ++i) {
		int parent, child;
		scanf("%d %d", &parent, &child);
		family[parent].push_back(child);
		family[child].push_back(parent);
	}
	queue<int>q;
	q.push(n1);
	vector<bool>visited(N + 1);
	for (int i = 0; i <= N; ++i) visited[i] = false;
	visited[n1] = true;
	bool success = false;
	int count = -1;
	while (!q.empty()) {
		int size = q.size();
		++count;
		// 현재 q에 있는 개수만큼 끊어서 tracking하면 bfs의 level을 쉽게 알 수 있음, level=촌수
		for (int j = 0; j < size; ++j) {
			int cur = q.front();
			if (cur == n2) {
				success = true;
				break;
			}
			q.pop();
			vector<int>next = family[cur];
			for (int i = 0; i < next.size(); ++i) {
				int target = next[i];
				if (!visited[target]) {
					visited[target] = true;
					q.push(target);
				}
			}
		}
		if (success) break;

	}
	if (success) printf("%d", count);
	else printf("%d", -1);
}