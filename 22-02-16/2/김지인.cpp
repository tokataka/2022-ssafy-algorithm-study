// https://www.acmicpc.net/problem/5212

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int R, C;
  cin >> R >> C;

  char map[10][10] = {0};
  for (int i = 0; i < R; i++) {
    cin >> map[i];
  }

  int direct[4][2] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  vector<pair<int, int>> sink;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (map[i][j] == '.') continue;

      int num_sea = 4;
      for (int d = 0; d < 4; d++) {
        int cur_i = i + direct[d][0];
        int cur_j = j + direct[d][1];
        if (cur_i >= 0 && cur_i < R && cur_j >= 0 && cur_j < C &&
            map[cur_i][cur_j] == 'X') {
          num_sea--;
        }
      }

      if (num_sea >= 3) sink.push_back(make_pair(i, j));
    }
  }

  for (auto it = sink.begin(); it != sink.end(); it++) {
    map[(*it).first][(*it).second] = '.';
  }

  int top = R;
  int bottom = -1;
  int left = C;
  int right = -1;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (map[i][j] == '.') continue;

      if (i < top) top = i;
      if (i > bottom) bottom = i;
      if (j < left) left = j;
      if (j > right) right = j;
    }
  }

  for (int i = top; i <= bottom; i++) {
    for (int j = left; j <= right; j++) {
      cout << map[i][j];
    }
    cout << '\n';
  }

  return 0;
}
