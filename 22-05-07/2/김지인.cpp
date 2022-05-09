#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main(int, char**) {
  string state = "";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int x;
      cin >> x;
      state.append(to_string(x));
    }
  }

  unordered_set<string> visited;
  queue<string> q;
  visited.insert(state);
  q.push(state);

  int direct[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
  int move_count = 0;

  while (!q.empty()) {
    int qs = q.size();
    for (int t = 0; t < qs; t++) {
      string cur = q.front();
      q.pop();

      if (cur == "123456780") {
        cout << move_count;
        return 0;
      }

      int loc = cur.find('0');
      int i = loc / 3;
      int j = loc % 3;

      for (int d = 0; d < 4; d++) {
        int di = i + direct[d][0];
        int dj = j + direct[d][1];
        if (di < 0 || di >= 3 || dj < 0 || dj >= 3) continue;

        char temp = cur[di * 3 + dj];
        string next = cur;
        next[i * 3 + j] = temp;
        next[di * 3 + dj] = '0';
        if (visited.find(next) != visited.end()) continue;

        visited.insert(next);
        q.push(next);
      }
    }

    move_count++;
  }

  cout << -1;

  return 0;
}
