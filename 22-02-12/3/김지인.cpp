// https://www.acmicpc.net/problem/16922

#include <iostream>
#include <unordered_set>
using namespace std;

int main(void) {
  int rom[4] = {1, 5, 10, 50};
  unordered_set<int> s;

  int n;
  cin >> n;

  for (int i = 0; i <= n; i++) {
    int rom_i = i * rom[0];
    for (int j = 0; j <= n - i; j++) {
      int rom_j = j * rom[1];
      for (int k = 0; k <= n - i - j; k++) {
        int rom_k = k * rom[2];
        int l = n - i - j - k;
        int rom_l = l * rom[3];
        int sum = rom_i + rom_j + rom_k + rom_l;
        s.insert(sum);
      }
    }
  }

  cout << s.size();
}
