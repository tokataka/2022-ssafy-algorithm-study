#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct Ant {
  int id;
  int time_to_drop;
};

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N, L, k;
    cin >> N >> L >> k;

    vector<int> ids;
    vector<int> left_time_to_drop;
    vector<int> right_time_to_drop;

    for (int i = 0; i < N; i++) {
      int p, id;
      cin >> p >> id;
      ids.push_back(id);
      if (id < 0) {
        left_time_to_drop.push_back(p + 1);
      } else {
        right_time_to_drop.push_back(L - p + 1);
      }
    }

    sort(left_time_to_drop.begin(), left_time_to_drop.end());
    sort(right_time_to_drop.begin(), right_time_to_drop.end());

    vector<Ant> ants;

    for (int i = 0; i < left_time_to_drop.size(); i++) {
      ants.push_back({ids[i], left_time_to_drop[i]});
    }

    for (int i = 0; i < right_time_to_drop.size(); i++) {
      ants.push_back({ids[ids.size() - 1 - i], right_time_to_drop[i]});
    }

    sort(ants.begin(), ants.end(), [](Ant a, Ant b) {
      if (a.time_to_drop != b.time_to_drop) {
        return a.time_to_drop < b.time_to_drop;
      }
      return a.id < b.id;
    });

    cout << ants[k - 1].id << "\n";
  }

  return 0;
}
