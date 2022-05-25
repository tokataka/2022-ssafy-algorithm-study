#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct State {
  int moves;
  int coins[2][2];
};

int main(int, char**) {
  int N, M;
  cin >> N >> M;

  int coin_cnt = 0;
  int wall_cnt = 0;

  int coins[2][2];
  int walls[400][2];
  int done[20][20][20][20] = {0};

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      if (s[j] == 'o') {
        coins[coin_cnt][0] = i;
        coins[coin_cnt][1] = j;
        coin_cnt++;
      } else if (s[j] == '#') {
        walls[wall_cnt][0] = i;
        walls[wall_cnt][1] = j;
        wall_cnt++;
      }
    }
  }

  queue<State> q;
  q.push({0, {coins[0][0], coins[0][1], coins[1][0], coins[1][1]}});
  done[coins[0][0]][coins[0][1]][coins[1][0]][coins[1][1]] = 1;
  done[coins[1][0]][coins[1][1]][coins[0][0]][coins[0][1]] = 1;

  int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  while (!q.empty()) {
    State cur = q.front();
    q.pop();

    if (cur.moves == 10) break;

    for (int d = 0; d < 4; d++) {
      int drop_cnt = 0;
      int next_coins[2][2];

      for (int c = 0; c < 2; c++) {
        int di = cur.coins[c][0] + direct[d][0];
        int dj = cur.coins[c][1] + direct[d][1];
        if (di < 0 || di >= N || dj < 0 || dj >= M) {
          drop_cnt++;
          continue;
        }

        int blocked = 0;
        for (int w = 0; w < wall_cnt; w++) {
          if (walls[w][0] == di && walls[w][1] == dj) {
            blocked = 1;
            break;
          }
        }

        if (blocked) {
          next_coins[c][0] = cur.coins[c][0];
          next_coins[c][1] = cur.coins[c][1];
        } else {
          next_coins[c][0] = di;
          next_coins[c][1] = dj;
        }
      }

      if (drop_cnt == 1) {
        cout << cur.moves + 1;
        return 0;
      }

      if (drop_cnt == 2) continue;

      if (next_coins[0][0] == next_coins[1][0] &&
          next_coins[0][1] == next_coins[1][1])
        continue;

      if (done[next_coins[0][0]][next_coins[0][1]][next_coins[1][0]]
              [next_coins[1][1]]) {
        continue;
      }

      done[next_coins[0][0]][next_coins[0][1]][next_coins[1][0]]
          [next_coins[1][1]] = 1;
      done[next_coins[1][0]][next_coins[1][1]][next_coins[0][0]]
          [next_coins[0][1]] = 1;

      q.push({cur.moves + 1,
              {next_coins[0][0], next_coins[0][1], next_coins[1][0],
               next_coins[1][1]}});
    }
  }

  cout << -1;

  return 0;
}
