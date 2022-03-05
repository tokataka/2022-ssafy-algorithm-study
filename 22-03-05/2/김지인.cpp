#include <iostream>
using namespace std;

int A[10000];

int main(int, char**) {
  int N;
  long long M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int left = 0;
  int right = 0;
  long long sum = A[0];
  int result = 0;

  while (right < N) {
    if (sum == M) result++;

    if (sum <= M) {
      right++;
      sum += A[right];
      continue;
    }

    if (sum > M) {
      sum -= A[left];
      left++;
    }
  }

  cout << result;

  return 0;
}
