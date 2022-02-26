// https://programmers.co.kr/learn/courses/30/lessons/12977

#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, bool> prime_data;

bool is_prime(int x) {
  auto d = prime_data.find(x);
  if (d != prime_data.end()) return d->second;

  int root_x = int(sqrt(x));
  for (int i = 2; i <= root_x; i++) {
    if (x % i == 0) {
      prime_data[x] = false;
      return false;
    }
  }
  prime_data[x] = true;
  return true;
}

int solution(vector<int> nums) {
  int answer = 0;
  int n = nums.size();

  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        int cur = nums[i] + nums[j] + nums[k];
        if (is_prime(cur)) answer++;
      }
    }
  }

  return answer;
}

int main(void) {
  vector<int> nums = {1, 2, 7, 6, 4};
  cout << solution(nums);
}
