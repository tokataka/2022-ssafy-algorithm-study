// https://www.acmicpc.net/problem/11729

#include <iostream>
#include <vector>
using namespace std;

string output = "";

int hanoi(int n, int from, int to) {
  if (n == 1) {
    output += to_string(from) + " " + to_string(to) + "\n";
    return 1;
  }

  int total = 0;

  int temp_pos;
  if (from != 1 && to != 1) {
    temp_pos = 1;
  } else if (from != 2 && to != 2) {
    temp_pos = 2;
  } else {
    temp_pos = 3;
  }

  total += hanoi(n - 1, from, temp_pos);
  total += hanoi(1, from, to);
  total += hanoi(n - 1, temp_pos, to);

  return total;
}

int main(void) {
  int n;
  cin >> n;

  cout << hanoi(n, 1, 3) << "\n" << output;
}
