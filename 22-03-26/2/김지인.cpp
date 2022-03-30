#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int main(int, char**) {
  string S;
  cin >> S;

  int N;
  cin >> N;

  string A[100];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  queue<string> q;
  unordered_set<string> done;
  q.push(S);

  while (!q.empty()) {
    string temp = q.front();
    q.pop();

    for (int i = 0; i < N; i++) {
      string a = A[i];
      if (temp.substr(0, a.size()) == a) {
        string next = temp.substr(a.size());
        if (next == "") {
          cout << 1;
          return 0;
        }

        if (done.find(next) != done.end()) continue;
        done.insert(next);

        q.push(next);
      }
    }
  }

  cout << 0;
  return 0;
}
