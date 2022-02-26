// https://www.acmicpc.net/problem/14501

#include <iostream>
using namespace std;

int N;
int schedule[15][2];
int dat[15];

int calc(int idx) {
  if (idx >= N) return 0;

  if (dat[idx]) return dat[idx];

  int result;
  if (idx + schedule[idx][0] > N) {
    result = calc(idx + 1);
  } else {
    result =
        max(calc(idx + 1), schedule[idx][1] + calc(idx + schedule[idx][0]));
  }

  dat[idx] = result;
  return result;
}

int main(void) {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> schedule[i][0] >> schedule[i][1];
  }

  int result = calc(0);

  cout << result;
}
