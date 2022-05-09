#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
long long construct_time[1001];
long long need_time[1001];
vector<int> prereq[1001];

long long func(int x) {
  if (need_time[x]) {
    return need_time[x];
  }

  long long max_time = 0;
  for (int i = 0; i < prereq[x].size(); i++) {
    long long ret = need_time[prereq[x][i]];
    if (ret == 0) {
      ret = func(prereq[x][i]);
    }
    if (ret > max_time) max_time = ret;
  }

  need_time[x] = construct_time[x] + max_time;
  return need_time[x];
}

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
      prereq[i].clear();
      need_time[i] = 0;
      cin >> construct_time[i];
    }

    for (int i = 0; i < K; i++) {
      int a, b;
      cin >> a >> b;
      prereq[b].push_back(a);
    }

    int W;
    cin >> W;

    cout << func(W) << "\n";
  }

  return 0;
}
