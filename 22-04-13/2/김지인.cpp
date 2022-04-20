#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int water[3];
};

int done[201][201][201] = {0};
int result[201] = {0};

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int b_size[3];
  cin >> b_size[0] >> b_size[1] >> b_size[2];

  queue<Node> q;
  q.push({0, 0, b_size[2]});
  done[0][0][b_size[2]] = 1;
  result[b_size[2]] = 1;

  while (!q.empty()) {
    Node cur = q.front();
    q.pop();

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j) continue;
        if (cur.water[i] == 0) continue;
        if (cur.water[j] == b_size[j]) continue;

        Node next = {cur.water[0], cur.water[1], cur.water[2]};

        if (b_size[j] - cur.water[j] >= cur.water[i]) {
          next.water[j] += next.water[i];
          next.water[i] = 0;
        } else {
          next.water[i] -= (b_size[j] - cur.water[j]);
          next.water[j] = b_size[j];
        }

        if (done[next.water[0]][next.water[1]][next.water[2]] == 1) continue;

        q.push(next);
        done[next.water[0]][next.water[1]][next.water[2]] = 1;
        if (next.water[0] == 0) {
          result[next.water[2]] = 1;
        }
      }
    }
  }

  for (int i = 1; i < b_size[2]; i++) {
    if (result[i]) {
      cout << i << " ";
    }
  }

  cout << b_size[2];

  return 0;
}
