#include <iostream>
#include <queue>
#include<vector>

using namespace std;

struct Edge {
	int to;
	int cost;
};

struct cmp {
	bool operator() (Edge right, Edge left) {
		if (left.cost < right.cost) return true;
		else if (left.cost > right.cost) return false;
	}
};

int V, E, start;
int dist[20001] = { 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E >> start;
	vector<vector<Edge>> arr(V+1, vector<Edge>());
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		arr[u].push_back({ v, w });
	}

	for (int i = 1; i <= V; i++) {
		dist[i] = 2134567890;
	}

	priority_queue<Edge, vector<Edge>, cmp> pq;
	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		for (int i = 0; i < arr[now.to].size(); i++) {
			int to = arr[now.to][i].to;
			int cost = arr[now.to][i].cost;
			if (dist[to] <= cost + now.cost) continue;
			dist[to] = cost + now.cost;
			pq.push({ to, dist[to] });
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == 2134567890) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}