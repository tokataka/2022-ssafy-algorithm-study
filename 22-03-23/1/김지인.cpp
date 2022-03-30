#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int K, N;
  cin >> K >> N;

  priority_queue<long long, vector<long long>, greater<long long>> pq;
  set<long long> done;
  vector<long long> primes;

  for (int i = 0; i < K; i++) {
    long long x;
    cin >> x;
    pq.push(x);
    done.insert(x);
    primes.push_back(x);
  }

  long long temp = 0;
  long long max_value = 0;
  for (int i = 0; i < N - 1; i++) {
    temp = pq.top();
    pq.pop();

    for (auto el : primes) {
      long long next = temp * el;
      if (done.find(next) != done.end()) continue;
      if (next > 1LL << 31) continue;
      if (pq.size() > N - i && next > max_value) continue;
      pq.push(next);
      done.insert(next);
      if (next > max_value) {
        max_value = next;
      }
    }
  }

  cout << pq.top();

  return 0;
}
