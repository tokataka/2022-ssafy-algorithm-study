#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  long long value;
  int count;
};

bool operator<(Node a, Node b) {
  if (a.value != b.value) return a.value > b.value;
  return a.count > b.count;
}

int main(int, char**) {
  long long A, B;
  cin >> A >> B;

  priority_queue<Node> q;
  q.push({A, 1});

  while (!q.empty()) {
    Node x = q.top();
    q.pop();

    if (x.value == B) {
      cout << x.count;
      return 0;
    }

    if (x.value > B) {
      cout << -1;
      return 0;
    }

    q.push({x.value * 2, x.count + 1});
    q.push({x.value * 10 + 1, x.count + 1});
  }

  return 0;
}
