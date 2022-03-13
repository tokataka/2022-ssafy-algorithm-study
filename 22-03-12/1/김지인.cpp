#include <iostream>
using namespace std;

struct Edge {
  int from;
  int to;
  long long weight;
};

Edge edges[6000];
long long distances[501];

int main(int, char**) {
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    edges[i] = {A, B, C};
  }

  distances[1] = 0;
  for (int i = 2; i <= N; i++) {
    distances[i] = INT64_MAX;
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < M; j++) {
      if (distances[edges[j].from] == INT64_MAX) continue;

      if (distances[edges[j].to] > distances[edges[j].from] + edges[j].weight) {
        distances[edges[j].to] = distances[edges[j].from] + edges[j].weight;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    if (distances[edges[i].from] == INT64_MAX) continue;

    if (distances[edges[i].to] > distances[edges[i].from] + edges[i].weight) {
      cout << -1;
      return 0;
    }
  }

  for (int i = 2; i <= N; i++) {
    if (distances[i] == INT64_MAX) {
      cout << -1 << "\n";
    } else {
      cout << distances[i] << "\n";
    }
  }

  return 0;
}
