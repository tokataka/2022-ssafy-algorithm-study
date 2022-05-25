#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
  vector<long long> answer;
  unordered_map<long long, long long> next_empty_room;

  for (auto cur_room_number : room_number) {
    vector<long long> route;

    while (next_empty_room.find(cur_room_number) != next_empty_room.end()) {
      route.push_back(cur_room_number);
      cur_room_number = next_empty_room[cur_room_number];
    }

    answer.push_back(cur_room_number);
    next_empty_room[cur_room_number] = cur_room_number + 1;
    for (auto r : route) {
      next_empty_room[r] = cur_room_number + 1;
    }
  }

  return answer;
}

int main(int, char**) {
  vector<long long> ret = solution(10, {1, 3, 4, 1, 3, 1});

  return 0;
}
