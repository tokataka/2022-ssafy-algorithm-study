// https://www.acmicpc.net/problem/1817

#include <iostream>
using namespace std;

int main(int, char**) {
  int N, M;
  cin >> N >> M;

  int books[50];
  for (int i = 0; i < N; i++) {
    cin >> books[i];
  }

  int box_count = 0;
  int remaining = 0;

  for (int i = 0; i < N; i++) {
    int cur_book = books[i];
    if (cur_book <= remaining) {
      remaining -= cur_book;
    } else {
      remaining = M - cur_book;
      box_count++;
    }
  }

  cout << box_count;

  return 0;
}
