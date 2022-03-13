#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int visit_cost[10001];
struct Edge {
	int to;
	int cost;
};
vector<Edge> v[10001];
int used[10001];

struct cmp {
	bool operator() (Edge right, Edge left){
		return left.cost < right.cost;
	}
};

int main() {
	int N, P;
	cin >> N >> P;
	for (int i = 1; i <= N; i++) {
		cin >> visit_cost[i];
	}

	for (int i = 0; i < P; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, 2 * cost + visit_cost[from] + visit_cost[to] });
		v[to].push_back({ from, 2 * cost + visit_cost[from] + visit_cost[to] });
	}

	priority_queue<Edge, vector<Edge>, cmp> pq;

	for (int i = 0; i < v[1].size(); i++) {
		int to = v[1][i].to;
		int cost = v[1][i].cost;
		pq.push({ to, cost });
	}

	used[1] = 1;

	int sum = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		int to = now.to;
		int cost = now.cost;
		if (used[to]) continue;
		used[to] = 1;
		sum += cost;

		for (int i = 0; i < v[to].size(); i++) {
			int t = v[to][i].to;
			int c = v[to][i].cost;
			pq.push({ t, c });
		}
	}

	sort(&visit_cost[1], &visit_cost[N+1]);
	cout << sum + visit_cost[1];
	return 0;
}