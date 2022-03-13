#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

char map[50][51];
bool near_garbage[50][50];
bool done[50][50];

struct Node {
  int i;
  int j;
  int garbage_count;
  int garbage_near_count;
};

bool operator<(Node a, Node b) {
  if (a.garbage_count > b.garbage_count) return true;
  if (a.garbage_count < b.garbage_count) return false;
  if (a.garbage_near_count > b.garbage_near_count) return true;
  if (a.garbage_near_count < b.garbage_near_count) return false;
  if (a.i > b.i) return true;
  if (a.i < b.i) return false;
  return a.j > b.j;
}

int main(int, char**) {
  int N, M;
  cin >> N >> M;

  int direct[4][2] = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  priority_queue<Node> pq;

  for (int i = 0; i < N; i++) {
    cin >> map[i];
    for (int j = 0; j < M; j++) {
      if (map[i][j] == 'S') {
        pq.push({i, j, 0, 0});
        done[i][j] = true;
      }
      if (map[i][j] == 'g') {
        for (int d = 0; d < 4; d++) {
          int ci = i + direct[d][0];
          int cj = j + direct[d][1];
          if (ci < 0 || ci >= N || cj < 0 || cj >= M) continue;
          near_garbage[ci][cj] = true;
        }
      }
    }
  }

  while (!pq.empty()) {
    Node cur = pq.top();
    pq.pop();

    int i = cur.i;
    int j = cur.j;

    for (int d = 0; d < 4; d++) {
      int ci = i + direct[d][0];
      int cj = j + direct[d][1];
      if (ci < 0 || ci >= N || cj < 0 || cj >= M) continue;
      if (done[ci][cj]) continue;

      if (map[ci][cj] == 'F') {
        cout << cur.garbage_count << " " << cur.garbage_near_count;
        return 0;
      }

      int next_garbage_count = cur.garbage_count;
      int next_garbage_near_count = cur.garbage_near_count;
      if (map[ci][cj] == 'g') {
        next_garbage_count++;
      } else {
        next_garbage_near_count += near_garbage[ci][cj];
      }

      pq.push({ci, cj, next_garbage_count, next_garbage_near_count});
      done[ci][cj] = true;
    }
  }

  return 0;
}
