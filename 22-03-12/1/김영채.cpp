#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

struct Edge {
	int start;
	int end;
	int time;
};
int N, M;
vector<Edge> v;
long long dist[501];

void bellmanford() {
	dist[1] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			if (dist[v[j].start] == 2134567890) continue;
			if (dist[v[j].end] > dist[v[j].start] + v[j].time) dist[v[j].end] = dist[v[j].start] + v[j].time;
		}
	}

	for (int i = 0; i < M; i++) {
		if (dist[v[i].start] == 2134567890) continue;
		if (dist[v[i].end] > dist[v[i].start] + v[i].time) {
			cout << -1 << endl;
			return;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (dist[i] == 2134567890) cout << -1 << endl;
		else cout << dist[i] << endl;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dist[i] = 2134567890;
	}

	for (int i = 0; i < M; i++) {
		int start, end, time;
		cin >> start >> end >> time;
		v.push_back({ start, end, time });
		
	}

	bellmanford();

	return 0;
}