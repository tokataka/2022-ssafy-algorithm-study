#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;

int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// 0: something moved, 1: red out, 2: blue out, 3: nothing happen
int tilt(vector<string>& board, int mode) {
  int R_i, R_j, B_i, B_j;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 'R') {
        R_i = i;
        R_j = j;
      }
      if (board[i][j] == 'B') {
        B_i = i;
        B_j = j;
      }
    }
  }

  int di = direct[mode][0];
  int dj = direct[mode][1];

  int total_moved = 0;
  int red_out = 0;
  int blue_out = 0;

  while (1) {
    int moved = 0;

    if (!red_out && board[R_i + di][R_j + dj] == 'O') {
      red_out = 1;
      board[R_i][R_j] = '.';
      moved = 1;
      total_moved = 1;
    }
    if (!blue_out && board[B_i + di][B_j + dj] == 'O') {
      blue_out = 1;
      board[B_i][B_j] = '.';
      moved = 1;
      total_moved = 1;
    }

    if (!red_out && board[R_i + di][R_j + dj] == '.') {
      board[R_i][R_j] = '.';
      board[R_i + di][R_j + dj] = 'R';
      R_i += di;
      R_j += dj;
      moved = 1;
      total_moved = 1;
    }

    if (!blue_out && board[B_i + di][B_j + dj] == '.') {
      board[B_i][B_j] = '.';
      board[B_i + di][B_j + dj] = 'B';
      B_i += di;
      B_j += dj;
      moved = 1;
      total_moved = 1;
    }

    if (moved == 0) break;
  }

  if (total_moved == 0) return 3;
  if (blue_out) return 2;
  if (red_out) return 1;

  return 0;
}

int dfs(vector<string> board, int lv) {
  if (lv == 10) return 0;

  for (int d = 0; d < 4; d++) {
    vector<string> next_board = board;
    int ret = tilt(next_board, d);

    if (ret == 1) return 1;
    if (ret == 2) continue;
    if (ret == 3) continue;

    ret = dfs(next_board, lv + 1);
    if (ret == 1) return 1;
  }

  return 0;
}

int main(int, char**) {
  cin >> N >> M;

  vector<string> board;

  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    board.push_back(s);
  }

  printf("%d", dfs(board, 0));

  return 0;
}
