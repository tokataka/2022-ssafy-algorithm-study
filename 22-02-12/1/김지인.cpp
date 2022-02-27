// https://programmers.co.kr/learn/courses/30/lessons/43163

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct state {
  string str;
  int count;
};

int get_distance(string a, string b) {
  int distance = 0;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) distance++;
  }

  return distance;
}

int solution(string begin, string target, vector<string> words) {
  bool done[50] = {0};

  queue<state> q;
  q.push({begin, 0});

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (int i = 0; i < words.size(); i++) {
      if (done[i]) continue;
      if (get_distance(cur.str, words[i]) != 1) continue;

      if (words[i] == target) return cur.count + 1;
      done[i] = true;

      q.push({words[i], cur.count + 1});
    }
  }

  return 0;
}

int main(void) {
  string begin = "hit";
  string target = "cog";
  vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};

  int answer = solution(begin, target, words);

  cout << answer;

  return 0;
}
