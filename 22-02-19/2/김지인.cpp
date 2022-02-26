// https://www.acmicpc.net/problem/1026

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<int> A(n);
  vector<int> B(n);

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }

  vector<int> sortkey(n);
  for (int i = 0; i < n; i++) {
    sortkey[i] = i;
  }

  sort(sortkey.begin(), sortkey.end(),
       [&](auto a, auto b) { return B[a] > B[b]; });

  sort(A.begin(), A.end(), [](auto a, auto b) { return a < b; });

  vector<int> temp(n);
  for (int i = 0; i < n; i++) {
    temp[sortkey[i]] = A[i];
  }

  A = temp;

  int S = 0;
  for (int i = 0; i < n; i++) {
    S += A[i] * B[i];
  }

  cout << S;
}
