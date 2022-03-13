#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

bool visited[1000000];

int main(int, char**) {
  int N;
  cin >> N;

  if (N == 1) {
    cout << 0;
    return 0;
  }

  queue<int> q;
  q.push(1);
  int cycle = 1;
  bool found = false;

  while (true) {
    int q_size = q.size();
    for (int i = 0; i < q_size; i++) {
      int cur = q.front();
      q.pop();

      if (cur * 3 == N || cur * 2 == N || cur + 1 == N) {
        found = true;
        break;
      }

      int next[3] = {cur * 3, cur * 2, cur + 1};
      for (int j = 0; j < 3; j++) {
        if (next[j] < 1000000 && !visited[next[j]]) {
          q.push(next[j]);
          visited[next[j]] = true;
        }
      }
    }

    if (found) break;

    cycle++;
  }

  cout << cycle;

  return 0;
}
