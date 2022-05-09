#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int start;
  int end;
};

bool operator<(Node a, Node b) {
  if (a.start != b.start) return a.start > b.start;
  return a.end > b.end;
}

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int N;
  cin >> N;

  priority_queue<Node> pq_meeting;

  for (int i = 0; i < N; i++) {
    Node n;
    cin >> n.start >> n.end;
    pq_meeting.push(n);
  }

  priority_queue<int, vector<int>, greater<>> pq_room;
  pq_room.push(pq_meeting.top().end);
  pq_meeting.pop();

  while (!pq_meeting.empty()) {
    Node cur = pq_meeting.top();
    pq_meeting.pop();

    int room = pq_room.top();
    if (cur.start >= room) {
      pq_room.pop();
      pq_room.push(cur.end);
    } else {
      pq_room.push(cur.end);
    }
  }

  cout << pq_room.size();

  return 0;
}
