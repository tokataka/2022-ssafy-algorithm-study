#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  priority_queue<int, vector<int>, less<int>> pq_left;
  priority_queue<int, vector<int>, greater<int>> pq_right;

  int middle;
  cin >> middle;

  cout << middle << "\n";

  for (int i = 0; i < N - 1; i++) {
    int x;
    cin >> x;
    if (x < middle) {
      pq_left.push(x);
    } else {
      pq_right.push(x);
    }

    if (pq_left.size() > pq_right.size()) {
      pq_right.push(middle);
      middle = pq_left.top();
      pq_left.pop();
    }

    if (pq_left.size() < pq_right.size() - 1) {
      pq_left.push(middle);
      middle = pq_right.top();
      pq_right.pop();
    }

    cout << middle << "\n";
  }

  return 0;
}
