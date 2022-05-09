#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, W;
int plum[1000];
int max_plum[1000][31];

int func(int cur, int move) {
  if (cur >= T) return 0;
  if (move > W) return 0;
  if (max_plum[cur][move] >= 0) return max_plum[cur][move];

  int ret = (plum[cur] == (move % 2) ? 1 : 0);
  ret += max(func(cur + 1, move), func(cur + 1, move + 1));
  max_plum[cur][move] = ret;
  return ret;
}

int main(int, char**) {
  cin >> T >> W;

  for (int i = 0; i < T; i++) {
    int x;
    cin >> x;
    plum[i] = x - 1;
  }

  for (int i = 0; i < T; i++) {
    for (int j = 0; j <= W; j++) {
      max_plum[i][j] = -1;
    }
  }

  cout << max(func(0, 0), func(0, 1));

  return 0;
}
