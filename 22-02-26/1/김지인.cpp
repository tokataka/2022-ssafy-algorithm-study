// https://www.acmicpc.net/problem/14888

#include <iostream>
using namespace std;

int N;
int A[11];
int ops[4];
long long maxValue = INT64_MIN;
long long minValue = INT64_MAX;
long long history[11];

void dfs(int level) {
  if (level == N - 1) {
    if (history[N - 1] > maxValue) maxValue = history[N - 1];
    if (history[N - 1] < minValue) minValue = history[N - 1];
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (ops[i] == 0) continue;
    if (i == 0) {
      history[level + 1] = history[level] + A[level + 1];
    } else if (i == 1) {
      history[level + 1] = history[level] - A[level + 1];
    } else if (i == 2) {
      history[level + 1] = history[level] * A[level + 1];
    } else if (i == 3) {
      history[level + 1] = history[level] / A[level + 1];
    }
    ops[i]--;
    dfs(level + 1);
    ops[i]++;
  }
}

int main(int, char**) {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < 4; i++) {
    cin >> ops[i];
  }

  history[0] = A[0];
  dfs(0);

  cout << maxValue << "\n" << minValue;

  return 0;
}
