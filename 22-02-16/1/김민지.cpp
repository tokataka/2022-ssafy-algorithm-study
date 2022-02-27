#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int N;
vector<vector<int>>graph(201);
int visited[201];
int answer;

void dfs(int node) {
	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); ++i) {
		if (visited[graph[node][i]] == 0) dfs(node);
	}
}

int solution(int n, vector<vector<int>>computers) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (computers[i][j] == 1) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (visited[i] == 0) {
			++answer;
			cout << i << endl;
			dfs(i);
		}
	}
	return answer;
}