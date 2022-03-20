#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int castle[50][50];

pair<int, int> u_root[50][50];
pair<int, int> u_find(pair<int, int> p) {
  pair<int, int> temp = p;
  while (u_root[temp.first][temp.second] != temp) {
    temp = u_root[temp.first][temp.second];
  }

  u_root[p.first][p.second] = temp;

  return temp;
}
void u_union(pair<int, int> p1, pair<int, int> p2) {
  p1 = u_find(p1);
  p2 = u_find(p2);

  if (p1 == p2) return;

  u_root[p2.first][p2.second] = p1;
}

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int M, N;
  cin >> M >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> castle[i][j];
      u_root[i][j] = make_pair(i, j);
    }
  }

  int direct[4][2] = {
      {0, -1},
      {-1, 0},
      {0, 1},
      {1, 0},
  };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int wall = castle[i][j];

      for (int d = 0; d < 4; d++) {
        if (wall % 2 == 0) {
          int di = i + direct[d][0];
          int dj = j + direct[d][1];
          u_union(make_pair(i, j), make_pair(di, dj));
        }

        wall /= 2;
      }
    }
  }

  map<pair<int, int>, int> room_size;
  int max_room_size = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      auto r = u_find(make_pair(i, j));
      if (room_size.find(r) == room_size.end()) {
        room_size[r] = 1;
      } else {
        room_size[r]++;
      }
      if (room_size[r] > max_room_size) {
        max_room_size = room_size[r];
      }
    }
  }

  int max_room_size_w_break = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int wall = castle[i][j];

      auto r1 = u_find(make_pair(i, j));

      for (int d = 0; d < 4; d++) {
        if (wall % 2 == 1) {
          int di = i + direct[d][0];
          int dj = j + direct[d][1];
          if (di < 0 || di >= N || dj < 0 || dj >= M) continue;

          auto r2 = u_find(make_pair(di, dj));
          if (r1 == r2) continue;

          int sum_size = room_size[r1] + room_size[r2];
          if (sum_size > max_room_size_w_break) {
            max_room_size_w_break = sum_size;
          }
        }

        wall /= 2;
      }
    }
  }

  cout << room_size.size() << "\n";
  cout << max_room_size << "\n";
  cout << max_room_size_w_break << "\n";

  return 0;
}
