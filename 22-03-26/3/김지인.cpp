#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int board[500][500];
int visited[500][500][10][2];

int main(int, char**) {
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));

  int day = 1;
  int steps = 0;
  bool is_night = false;

  int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  while (!q.empty()) {
    int q_size = q.size();

    for (int q_idx = 0; q_idx < q_size; q_idx++) {
      auto cur = q.front();
      q.pop();

      int i = cur.first;
      int j = cur.second;

      if (i == N - 1 && j == N - 1) {
        cout << day << " " << (is_night ? "moon" : "sun");
        return 0;
      }

      for (int d = 0; d < 4; d++) {
        int di = i + direct[d][0];
        int dj = j + direct[d][1];
        if (di < 0 || di >= N || dj < 0 || dj >= N) continue;
        if (!is_night && board[di][dj] == 1) continue;
        if (is_night && board[di][dj] == 1) {
          bool is_valid = true;
          while (true) {
            di += direct[d][0];
            dj += direct[d][1];
            if (di < 0 || di >= N || dj < 0 || dj >= N) {
              is_valid = false;
              break;
            }
            if (board[di][dj] == 0) {
              break;
            }
          }
          if (!is_valid) continue;
        }

        if (visited[di][dj][steps][is_night]) continue;
        visited[di][dj][steps][is_night] = 1;

        q.push(make_pair(di, dj));
      }
    }

    steps++;
    if (steps == M) {
      steps = 0;
      is_night = !is_night;
      if (!is_night) {
        day++;
      }
    }
  }

  cout << -1;

  return 0;
}
