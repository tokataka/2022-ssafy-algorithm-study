#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> d;

int main(int, char**) {
  int result = 0;

  int N;
  cin >> N;

  d.push_back(0);

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    if (x > d.back()) {
      d.push_back(x);
    } else {
      auto it = lower_bound(d.begin(), d.end(), x);
      *it = x;
    }
  }

  cout << (d.size() - 1);

  return 0;
}
