#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int board[100][100];
int done[100][100];

int main(int, char**) {
  int M, N, K;
  cin >> M >> N >> K;

  for (int k = 0; k < K; k++) {
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;

    for (int i = i1; i < i2; i++) {
      for (int j = j1; j < j2; j++) {
        board[i][j] = 1;
      }
    }
  }

  int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector<int> result;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 1 || done[i][j]) continue;

      int count = 0;
      queue<pair<int, int>> q;
      q.push(make_pair(i, j));
      done[i][j] = 1;

      while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int ci = cur.first;
        int cj = cur.second;

        count++;

        for (int d = 0; d < 4; d++) {
          int di = ci + direct[d][0];
          int dj = cj + direct[d][1];

          if (di < 0 || di >= N) continue;
          if (dj < 0 || dj >= M) continue;
          if (board[di][dj] == 1) continue;
          if (done[di][dj]) continue;

          q.push(make_pair(di, dj));
          done[di][dj] = 1;
        }
      }

      result.push_back(count);
    }
  }

  sort(result.begin(), result.end());

  cout << result.size() << "\n";
  for (int el : result) {
    cout << el << " ";
  }

  return 0;
}
