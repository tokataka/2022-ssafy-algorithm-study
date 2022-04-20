#include <algorithm>
#include <iostream>
using namespace std;

int a[100000];

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  sort(a, a + N);

  int M;
  cin >> M;

  int x;
  for (int i = 0; i < M; i++) {
    cin >> x;

    int left = 0;
    int right = N - 1;
    int mid;
    int found = false;

    while (right - left >= 0) {
      mid = (left + right) / 2;

      if (a[mid] == x) {
        cout << "1\n";
        found = true;
        break;
      }

      if (a[mid] < x) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    if (!found) {
      cout << "0\n";
    }
  }

  return 0;
}
