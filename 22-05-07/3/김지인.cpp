#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int N, M, P;
int board[1000][1000];
int Sp[10];
queue<pair<int, int>> castles[10];
vector<pair<int, int>> temp_castles;
vector<pair<int, int>> next_castles;
int result[10];

struct Node {
  int i;
  int j;
  int count;
};

void expand(Node node) {
  queue<Node> q;
  q.push(node);

  int direct[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

  while (!q.empty()) {
    Node cur = q.front();
    q.pop();

    int i = cur.i;
    int j = cur.j;
    int count = cur.count;

    for (int d = 0; d < 4; d++) {
      int di = i + direct[d][0];
      int dj = j + direct[d][1];

      if (di < 0 || di >= N || dj < 0 || dj >= M) continue;
      if (board[di][dj] != 0 && board[di][dj] < 100) continue;
      if (board[di][dj] >= 100 + count) continue;
      if (board[di][dj] == 0) {
        temp_castles.push_back(make_pair(di, dj));
        if (count == 1) {
          next_castles.push_back(make_pair(di, dj));
        }
      }
      board[di][dj] = 100 + count;
      if (count > 1) {
        q.push({di, dj, count - 1});
      }
    }
  }
}

int main(int, char**) {
  cin >> N >> M >> P;

  for (int i = 1; i <= P; i++) {
    cin >> Sp[i];
  }

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      if (s[j] == '.') {
        board[i][j] = 0;
      } else if (s[j] == '#') {
        board[i][j] = -1;
      } else {
        int player = s[j] - '0';
        board[i][j] = player;
        castles[player].push(make_pair(i, j));
        result[player]++;
      }
    }
  }

  int turn = 1;

  while (1) {
    while (!castles[turn].empty()) {
      auto p = castles[turn].front();
      castles[turn].pop();
      expand({p.first, p.second, Sp[turn]});
    }

    for (auto p : temp_castles) {
      board[p.first][p.second] = turn;
      result[turn]++;
    }

    for (auto p : next_castles) {
      castles[turn].push(p);
    }

    temp_castles.clear();
    next_castles.clear();

    turn = ((turn % P) + 1);

    bool is_end = true;
    for (int i = 1; i <= P; i++) {
      if (!castles[i].empty()) {
        is_end = false;
        break;
      }
    }

    if (is_end) break;
  }

  for (int i = 1; i <= P; i++) {
    cout << result[i] << " ";
  }

  return 0;
}
