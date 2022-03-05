#include <iostream>
#include <queue>
using namespace std;

int map[1000][1000];
int virus_time[1000][1000];
queue<pair<int, int>> virus_q;

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
      if (map[i][j] > 0) {
        virus_q.push(make_pair(i, j));
        virus_time[i][j] = 1;
      }
    }
  }

  int direct[4][2] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  while (!virus_q.empty()) {
    auto v = virus_q.front();
    virus_q.pop();

    int i = v.first;
    int j = v.second;

    int cur_virus = map[i][j];
    if (cur_virus == 3) continue;

    int cur_time = virus_time[i][j];

    for (int d = 0; d < 4; d++) {
      int ci = i + direct[d][0];
      int cj = j + direct[d][1];
      if (ci < 0 || ci >= N || cj < 0 || cj >= M) continue;
      if (map[ci][cj] == -1) continue;
      if (map[ci][cj] >= 1 && map[ci][cj] <= 2) {
        if (cur_virus + map[ci][cj] == 3 &&
            cur_time + 1 == virus_time[ci][cj]) {
          map[ci][cj] = 3;
        }
        continue;
      }
      if (map[ci][cj] == 3) continue;

      map[ci][cj] = cur_virus;
      virus_time[ci][cj] = cur_time + 1;
      virus_q.push(make_pair(ci, cj));
    }
  }

  int dat[4] = {0};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dat[map[i][j]]++;
    }
  }

  cout << dat[1] << " " << dat[2] << " " << dat[3];

  return 0;
}
