#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int map[50][50];
vector<pair<int, int>> viruses;
vector<int> selected_viruses;

int min_infect_time = INT32_MAX;

struct Node {
  int i;
  int j;
};

int infect_time() {
  int infected[50][50];
  int remain = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (map[i][j] == 1) {
        infected[i][j] = -1;
      } else if (map[i][j] == 2) {
        infected[i][j] = -2;
      } else if (map[i][j] == 0) {
        infected[i][j] = 0;
        remain++;
      }
    }
  }

  int result = 1;
  queue<pair<int, int>> q;
  for (auto el : selected_viruses) {
    q.push(viruses[el]);
    int i = viruses[el].first;
    int j = viruses[el].second;
    infected[i][j] = 1;
  }

  int direct[4][2] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    int i = cur.first;
    int j = cur.second;
    int t = infected[i][j];

    for (int d = 0; d < 4; d++) {
      int di = i + direct[d][0];
      int dj = j + direct[d][1];

      if (di < 0 || di >= N || dj < 0 || dj >= N) continue;
      if (infected[di][dj] == -2) {
        infected[di][dj] = t + 1;
        q.push(make_pair(di, dj));
      }
      if (infected[di][dj] != 0) continue;

      remain--;
      infected[di][dj] = t + 1;
      if (t + 1 > result) {
        result = t + 1;
      }
      q.push(make_pair(di, dj));
    }
  }

  if (remain != 0) return INT32_MAX;

  return result - 1;
}

void dfs(int lv, int start_idx) {
  if (lv == M) {
    int t = infect_time();
    if (t < min_infect_time) {
      min_infect_time = t;
    }

    return;
  }

  for (int i = start_idx; i < viruses.size(); i++) {
    selected_viruses.push_back(i);
    dfs(lv + 1, i + 1);
    selected_viruses.pop_back();
  }
}

int main(int, char**) {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int x;
      cin >> x;
      if (x == 2) {
        viruses.push_back(make_pair(i, j));
      }
      map[i][j] = x;
    }
  }

  dfs(0, 0);

  if (min_infect_time == INT32_MAX) {
    cout << -1;
  } else {
    cout << min_infect_time;
  }

  return 0;
}
