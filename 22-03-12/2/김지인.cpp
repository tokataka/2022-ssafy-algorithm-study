#include <algorithm>
#include <iostream>
using namespace std;

struct Edge {
  int from;
  int to;
  int weight;
};

int vertice[10001];

bool operator<(Edge a, Edge b) { return a.weight < b.weight; }

Edge edges[100000];
int parent[10001];

int find_set(int n) {
  int root = n;
  while (parent[root] != root) {
    root = parent[root];
  }
  parent[n] = root;
  return root;
}

void union_set(int a, int b) {
  int root_a = find_set(a);
  int root_b = find_set(b);
  parent[root_b] = root_a;
}

int main(int, char**) {
  int N, P;
  cin >> N >> P;

  int min_vertex = INT32_MAX;
  for (int i = 1; i <= N; i++) {
    cin >> vertice[i];
    if (vertice[i] < min_vertex) {
      min_vertex = vertice[i];
    }
  }

  for (int i = 0; i < P; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    edges[i] = {from, to, (2 * weight + vertice[from] + vertice[to])};
  }

  for (int i = 1; i <= N; i++) {
    parent[i] = i;
  }

  sort(edges, edges + P);

  int result = 0;

  for (int i = 0; i < P; i++) {
    int from = edges[i].from;
    int to = edges[i].to;
    int weight = edges[i].weight;

    if (find_set(from) == find_set(to)) continue;
    union_set(from, to);
    result += weight;
  }

  cout << result + min_vertex;

  return 0;
}
