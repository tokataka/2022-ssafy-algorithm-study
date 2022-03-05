#include <iostream>
#include <queue>
using namespace std;

char map[50][51];
int flood[50][50];
int move_count[50][50];
queue<pair<int, int>> hog_q;
queue<pair<int, int>> flood_q;

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int R, C;
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    cin >> map[i];
    for (int j = 0; j < C; j++) {
      if (map[i][j] == 'S') {
        hog_q.push(make_pair(i, j));
        move_count[i][j] = 1;
      }
      if (map[i][j] == '*') {
        flood_q.push(make_pair(i, j));
        flood[i][j] = 1;
      }
    }
  }

  int direct[4][2] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  while (!flood_q.empty()) {
    auto f = flood_q.front();
    flood_q.pop();
    int i = f.first;
    int j = f.second;
    int cur_flood = flood[i][j];

    for (int d = 0; d < 4; d++) {
      int ci = i + direct[d][0];
      int cj = j + direct[d][1];
      if (ci < 0 || ci >= R || cj < 0 || cj >= C) continue;
      if (flood[ci][cj]) continue;
      if (map[ci][cj] == 'X') continue;
      if (map[ci][cj] == 'D') continue;

      flood[ci][cj] = cur_flood + 1;
      flood_q.push(make_pair(ci, cj));
    }
  }

  while (!hog_q.empty()) {
    auto hog = hog_q.front();
    hog_q.pop();
    int i = hog.first;
    int j = hog.second;
    int cur_move_count = move_count[i][j];

    for (int d = 0; d < 4; d++) {
      int ci = i + direct[d][0];
      int cj = j + direct[d][1];
      if (ci < 0 || ci >= R || cj < 0 || cj >= C) continue;
      if (move_count[ci][cj]) continue;
      if (map[ci][cj] == 'X') continue;
      if (map[ci][cj] == 'D') {
        cout << cur_move_count;
        return 0;
      }

      if (flood[ci][cj] > 0 && flood[ci][cj] <= cur_move_count + 1) continue;

      move_count[ci][cj] = cur_move_count + 1;
      hog_q.push(make_pair(ci, cj));
    }
  }

  cout << "KAKTUS";
  return 0;
}
