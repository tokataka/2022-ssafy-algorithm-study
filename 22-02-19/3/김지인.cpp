// https://www.acmicpc.net/problem/2644

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void) {
  int parent[101] = {0};
  int n;
  cin >> n;

  int a, b;
  cin >> a >> b;

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    parent[y] = x;
  }

  // 루트까지 a의 조상들을 a_ancestors[ {{person}} ] = {{chon}}에 저장
  unordered_map<int, int> a_ancestors;
  int cur = a;
  int chon = 0;
  while (cur) {
    a_ancestors[cur] = chon;
    cur = parent[cur];
    chon++;
  }

  int result = -1;
  cur = b;
  chon = 0;

  // 루트까지 b의 조상을 탐색하면서 a_ancestors의 요소 중 하나라면
  // 그 지점부터 a와 b까지의 거리를 더하여 리턴
  while (cur) {
    auto d = a_ancestors.find(cur);
    if (d != a_ancestors.end()) {
      result = chon + d->second;
      break;
    }

    cur = parent[cur];
    chon++;
  }

  cout << result;
}
