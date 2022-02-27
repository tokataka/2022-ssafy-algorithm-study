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
	//n1, n2 �� ��� ����� ����������� �� �� ����
	//��������� �����ص� ���� ���� �� �ֵ��� ����� �׷����� ����
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
		// ���� q�� �ִ� ������ŭ ��� tracking�ϸ� bfs�� level�� ���� �� �� ����, level=�̼�
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