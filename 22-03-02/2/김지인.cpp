#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int ropes[100000];
  for (int i = 0; i < N; i++) {
    cin >> ropes[i];
  }

  sort(ropes, ropes + N, greater<>());

  int result = 0;
  for (int i = 0; i < N; i++) {
    int cur_weight = ropes[i] * (i + 1);
    if (cur_weight > result) result = cur_weight;
  }

  cout << result;

  return 0;
}
