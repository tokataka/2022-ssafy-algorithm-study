#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

typedef long long ll;

struct Status {
	int start, dst, cost;
};

int main() {
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	int N, M;
	ll dist[510];
	vector<Status>edges;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int start, dst, cost;
		scanf("%d %d %d", &start, &dst, &cost);
		edges.push_back({ start,dst,cost });
	}
	for (int i = 0; i <= N; ++i) dist[i] = 10e8;
	dist[1] = 0;
	for (int i = 1; i <= N - 1; ++i) {
		for (int j = 0; j < edges.size(); ++j) {
			int start = edges[j].start;
			int dst = edges[j].dst;
			int cost = edges[j].cost;
			if (dist[start] == 10e8) continue;
			if (dist[dst] > dist[start] + cost) dist[dst] = dist[start] + cost;
		}
	}
	bool fail = false;
	for (int i = 0; i < edges.size(); ++i) {
		int start = edges[j].start;
		int dst = edges[j].dst;
		int cost = edges[j].cost;
		if (dist[start] == 10e8) continue;
		if (dist[dst] > dist[start] + cost) {
			cout << -1;
			fail = true;
			break;
		}
	}
	if (!fail) {
		for (int i = 2; i <= N; ++i) {
			if (dist[i] == 10e8) printf("%d\n", -1);
			else printf("%d\n", dist[i]);
		}
	}
}