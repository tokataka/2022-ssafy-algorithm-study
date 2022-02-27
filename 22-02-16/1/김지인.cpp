// https://programmers.co.kr/learn/courses/30/lessons/43162

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
  int answer = 0;

  int remain = n;
  bool visited[200] = {0};
  queue<int> q;

  int cur = 0;
  while (remain > 0) {
    answer++;

    for (cur = 0; cur < n; cur++) {
      if (!visited[cur]) break;
    }

    q.push(cur);
    visited[cur] = true;
    remain--;

    while (!q.empty()) {
      cur = q.front();
      q.pop();

      for (int i = 0; i < n; i++) {
        if (cur == i) continue;
        if (visited[i]) continue;
        if (computers[cur][i] == 0) continue;

        q.push(i);
        visited[i] = true;
        remain--;
      }
    }
  }

  // int answer = n;

  // vector<unordered_set<int>> data;
  // data.resize(n);

  // for (int i = 0; i < n; i++) {
  //   data[i] = unordered_set<int>({i});
  // }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     if (i == j) continue;
  //     if (computers[i][j] == 0) continue;
  //     if (data[i].find(j) != data[i].end()) continue;

  //     for (auto it = data[j].begin(); it != data[j].end(); it++) {
  //       data[i].insert(*it);
  //     }

  //     for (auto it = data[i].begin(); it != data[i].end(); it++) {
  //       data[*it] = data[i];
  //     }
  //     answer--;
  //   }
  // }

  return answer;
}

int main(void) {
  vector<vector<int>> computers = {
      {1, 0, 0},
      {0, 1, 0},
      {0, 0, 1},
  };
  cout << solution(computers.size(), computers);
}
