// https://programmers.co.kr/learn/courses/30/lessons/42842

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
  for (int height = 1; height <= int(sqrt(yellow)); height++) {
    if (yellow % height != 0) continue;

    int width = yellow / height;

    if (brown == 2 * (height + width) + 4) {
      return {width + 2, height + 2};
    }
  }
  return {0, 0};
}

int main(void) {
  int input[3][2] = {
      {10, 2},
      {8, 1},
      {24, 24},
  };

  vector<int> output[3] = {
      {4, 3},
      {3, 3},
      {8, 6},
  };

  for (int i = 0; i < 3; i++) {
    auto result = solution(input[i][0], input[i][1]);
    if (result[0] == output[i][0] && result[1] == output[i][1]) {
      cout << "OK\n";
    } else {
      cout << "NG\n";
    }
  }
}
