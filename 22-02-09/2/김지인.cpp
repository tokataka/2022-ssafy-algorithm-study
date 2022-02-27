// https://www.acmicpc.net/problem/2206

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct loc {
  int i;
  int j;
};

bool operator==(loc a, loc b) { return a.i == b.i && a.j == b.j; }

struct state {
  loc pos;
  bool is_broken;
  int count;
};

int main(void) {
  int h, w;
  cin >> h >> w;

  bool map[1000][1000] = {0};
  char input[1001];

  for (int i = 0; i < h; i++) {
    cin >> input;
    for (int j = 0; j < w; j++) {
      map[i][j] = (input[j] == '1');
    }
  }

  queue<state> q;
  q.push(state{{0, 0}, false, 1});

  int count = 1;
  state result{{0, 0}, false, -1};

  int direct[4][2] = {
      {0, 1},
      {0, -1},
      {1, 0},
      {-1, 0},
  };

  bool visited[2][1000][1000] = {false};
  visited[0][0][0] = {true};

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    if (cur.pos == loc{h - 1, w - 1}) {
      result = cur;
      break;
    }

    for (int i = 0; i < 4; i++) {
      int next_i = cur.pos.i + direct[i][0];
      int next_j = cur.pos.j + direct[i][1];

      if (next_i < 0 || next_i >= h || next_j < 0 || next_j >= w) continue;
      if (map[next_i][next_j] == 1 && cur.is_broken) continue;

      bool next_broken = false;
      if (map[next_i][next_j] == 1 || cur.is_broken) {
        next_broken = true;
      }
      if (visited[next_broken][next_i][next_j]) continue;

      visited[next_broken][next_i][next_j] = true;
      q.push({
          {next_i, next_j},
          next_broken,
          cur.count + 1,
      });
    }
  }

  cout << result.count;
  return 0;
}
