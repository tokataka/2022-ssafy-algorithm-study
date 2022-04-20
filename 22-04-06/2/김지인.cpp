#include <iostream>
using namespace std;

int dat[1001];

int solution(int n) {
  if (dat[n]) return dat[n];
  if (n == 1) return 1;
  if (n == 2) return 2;

  int ret = (solution(n - 2) + solution(n - 1)) % 10007;
  dat[n] = ret;
  return ret;
}

int main(int, char**) {
  int n;
  cin >> n;
  cout << solution(n);
  return 0;
}
