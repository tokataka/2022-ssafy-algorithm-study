#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> node;
vector<vector<int>> sorted_x;
vector<vector<int>> sorted_y;
vector<vector<int>> sorted_z;

int main(int, char**) {
  int N;
  cin >> N;
  node.resize(N);
  sorted_x.resize(N);
  sorted_y.resize(N);
  sorted_z.resize(N);

  for (int i = 0; i < N; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    node[i] = {i, x, y, z};
  }

  sort(node.begin(), node.end(), [](auto a, auto b) { return a[1] < b[1]; });
  for (int i = 0; i < N; i++) {
    sorted_x[i] = node[i];
  }

  sort(node.begin(), node.end(), [](auto a, auto b) { return a[2] < b[2]; });
  for (int i = 0; i < N; i++) {
    sorted_y[i] = node[i];
  }

  sort(node.begin(), node.end(), [](auto a, auto b) { return a[3] < b[3]; });
  for (int i = 0; i < N; i++) {
    sorted_z[i] = node[i];
  }

  return 0;
}
