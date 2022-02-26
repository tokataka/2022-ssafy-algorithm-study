// https://www.acmicpc.net/problem/1343

#include <iostream>
using namespace std;

int main(int, char**) {
  string board;
  cin >> board;

  string result = "";

  int cur = 0;
  while (true) {
    while (board[cur] == '.' && cur < board.size()) {
      result += '.';
      cur++;
    }

    if (cur >= board.size()) break;

    string sub1 = board.substr(cur, 4);
    string sub2 = board.substr(cur, 2);

    if (sub1 == "XXXX") {
      result += "AAAA";
      cur += 4;
    } else if (sub2 == "XX") {
      result += "BB";
      cur += 2;
    } else {
      cout << "-1";
      return 0;
    }
  }

  cout << result;

  return 0;
}
