#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

char board[6][6];

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  vector<pair<int, int>> empty;
  vector<pair<int, int>> teacher;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'X') {
        empty.push_back(make_pair(i, j));
      }
      if (board[i][j] == 'T') {
        teacher.push_back(make_pair(i, j));
      }
    }
  }

  bool found = false;

  int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  for (int i = 0; i < empty.size(); i++) {
    for (int j = i + 1; j < empty.size(); j++) {
      for (int k = j + 1; k < empty.size(); k++) {
        char temp[6][6];
        for (int ii = 0; ii < N; ii++) {
          for (int jj = 0; jj < N; jj++) {
            temp[ii][jj] = board[ii][jj];
          }
        }

        temp[empty[i].first][empty[i].second] = 'O';
        temp[empty[j].first][empty[j].second] = 'O';
        temp[empty[k].first][empty[k].second] = 'O';

        bool evade = true;

        for (int t = 0; t < teacher.size(); t++) {
          int ti = teacher[t].first;
          int tj = teacher[t].second;

          for (int d = 0; d < 4; d++) {
            int c = 1;
            while (true) {
              int ci = ti + c * direct[d][0];
              int cj = tj + c * direct[d][1];
              if (ci < 0 || ci >= N || cj < 0 || cj >= N) break;
              if (temp[ci][cj] == 'O') break;
              if (temp[ci][cj] == 'S') {
                evade = false;
                break;
              }
              c++;
            }

            if (!evade) break;
          }
          if (!evade) break;
        }

        if (evade) {
          found = true;
          break;
        }
      }

      if (found) break;
    }
    if (found) break;
  }

  if (found)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}
