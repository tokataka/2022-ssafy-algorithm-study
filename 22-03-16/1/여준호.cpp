#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
	int to;
	int dist;
};

bool operator<(Edge left, Edge right)
{
	if (left.dist < right.dist) return false;
	if (left.dist > right.dist) return true;
	if (left.to < right.to) return false;
	if (left.to > right.to)return true;

	return false;
}

int V, E, K;
int dist[20005];
vector<vector<Edge>> v;

void input()
{
	v = vector<vector<Edge>>(V + 1, vector<Edge>());
	for (int i = 0; i < E; i++)
	{
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
	}
}

void solution()
{

	vector<int> dist(V + 1, 21e8);
	vector<int> used(V + 1, 0);

	priority_queue<Edge> pq;
	dist[K] = 0;
	pq.push({ K, 0 });

	while (!pq.empty()) 
	{
		Edge now = pq.top();
		pq.pop();

		int nowNode = now.to;
		int nowDist = now.dist;
		if (used[nowNode] == 1) continue;
		used[nowNode] = 1; 

		for (int i = 0; i < v[nowNode].size(); i++)
		{
			Edge edge = v[nowNode][i];
			int to = edge.to;
			int d = edge.dist;
			if (dist[to] <= dist[nowNode] + d) continue;
			dist[to] = dist[nowNode] + d;
			pq.push({ to, dist[to] });
		}
	}
	
	for (int i = 1; i <= V; i++) {
		if (dist[i] == 21e8) { cout << "INF"<<"\n"; }
		else cout << dist[i] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;
	cin >> K;
	
	input();
	solution();

	return 0;
}