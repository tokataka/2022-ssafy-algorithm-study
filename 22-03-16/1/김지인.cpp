#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<int, unordered_map<int, int>> graph;
int distances[20001];
int done[20001];

struct Node {
  int to;
  int distance;
};

bool operator<(Node a, Node b) { return a.distance > b.distance; }

int main(int, char**) {
  int V, E;
  cin >> V >> E;

  int K;
  cin >> K;

  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u][v] = w;
  }

  for (int i = 1; i <= V; i++) {
    distances[i] = INT32_MAX;
  }
  distances[K] = 0;

  priority_queue<Node> pq;
  pq.push({K, 0});
  done[K] = true;

  while (!pq.empty()) {
    auto now = pq.top();
    pq.pop();
    int min_node = now.to;

    for (int i = 1; i <= V; i++) {
      if (done[i]) continue;

      int d = graph[min_node][i];
      if (d == 0) continue;
      if (distances[i] < distances[min_node] + d) continue;
      distances[i] = distances[min_node] + d;
      done[i] = true;
      pq.push({i, distances[i]});
    }
  }

  for (int i = 1; i <= V; i++) {
    if (distances[i] == INT32_MAX) {
      cout << "INF\n";
    } else {
      cout << distances[i] << "\n";
    }
  }

  return 0;
}
