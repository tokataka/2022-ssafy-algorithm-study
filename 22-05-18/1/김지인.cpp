#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int, char**) {
  int N, M;
  cin >> N >> M;

  vector<queue<int>> sequences;
  int counts[1001] = {0};

  for (int i = 0; i < M; i++) {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      q.push(x);
      counts[x]++;
    }
    sequences.push_back(q);
  }

  vector<int> result;

  while (result.size() < N) {
    int cur_counts[1001] = {0};
    for (int i = 0; i < M; i++) {
      if (sequences[i].size() > 0) {
        cur_counts[sequences[i].front()]++;
      }
    }

    int is_poped = false;
    for (int c = 1; c <= N; c++) {
      if (counts[c] == cur_counts[c]) {
        result.push_back(c);
        for (int i = 0; i < M; i++) {
          if (sequences[i].size() > 0 && sequences[i].front() == c) {
            sequences[i].pop();
          }
        }
        is_poped = true;
        break;
      }
    }

    if (!is_poped) {
      cout << 0 << '\n';
      return 0;
    }
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << '\n';
  }

  return 0;
}
