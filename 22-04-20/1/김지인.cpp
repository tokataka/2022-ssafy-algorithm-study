#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[500][500];
int mem[500][500];

int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int func(int i, int j) {
  if (i == N - 1 && j == M - 1) return 1;

  if (mem[i][j] >= 0) {
    return mem[i][j];
  }

  int result = 0;
  for (int d = 0; d < 4; d++) {
    int di = i + direct[d][0];
    int dj = j + direct[d][1];
    if (di < 0 || di >= N || dj < 0 || dj >= M) {
      continue;
    }
    if (board[di][dj] >= board[i][j]) {
      continue;
    }

    result += func(di, dj);
  }

  mem[i][j] = result;
  return result;
}

int main(int, char**) {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
      mem[i][j] = -1;
    }
  }

  printf("%d", func(0, 0));

  return 0;
}
