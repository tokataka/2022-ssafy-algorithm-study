#include <iostream>
#include <queue>
using namespace std;

int board[300][300];
int visited[300][300];
int offset[300][300];

int main(int, char**) {
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  queue<pair<int, int>> q;
  int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int year = 0;

  while (1) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        visited[i][j] = 0;
        offset[i][j] = 0;

        if (board[i][j] > 0) {
          for (int d = 0; d < 4; d++) {
            int di = i + direct[d][0];
            int dj = j + direct[d][1];
            if (board[di][dj] == 0) {
              offset[i][j]++;
            }
          }
        }
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        board[i][j] -= offset[i][j];
        if (board[i][j] < 0) board[i][j] = 0;
      }
    }

    year++;

    int count = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[i][j] == 0) continue;
        if (visited[i][j]) continue;

        count++;
        if (count > 1) {
          cout << year;
          return 0;
        }

        q.push(make_pair(i, j));
        visited[i][j] = 1;

        while (!q.empty()) {
          auto cur = q.front();
          q.pop();

          int ci = cur.first;
          int cj = cur.second;

          for (int d = 0; d < 4; d++) {
            int di = ci + direct[d][0];
            int dj = cj + direct[d][1];

            if (board[di][dj] == 0) continue;
            if (visited[di][dj]) continue;

            visited[di][dj] = 1;

            q.push(make_pair(di, dj));
          }
        }
      }
    }

    if (count == 0) break;
  }

  cout << 0;

  return 0;
}
