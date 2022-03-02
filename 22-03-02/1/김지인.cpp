#include <iostream>
using namespace std;

int set[1000001];

int set_find(int x) {
  if (set[x] == x) return x;

  int ret = set_find(set[x]);
  set[x] = ret;
  return ret;
}

void set_union(int a, int b) {
  a = set_find(a);
  b = set_find(b);
  if (a == b) return;

  set[b] = a;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= n; i++) {
    set[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 0) {
      set_union(a, b);
    } else if (t == 1) {
      if (set_find(a) == set_find(b)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
