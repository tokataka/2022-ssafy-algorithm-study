#include <vector>
#include <iostream>
using namespace std;

int visited[50] = { 0 };
int path[50] = { 0 };
int answer = 0;

void isPrime(int sum) {
    int prime = 1;
    for (int i = 2; i < sum; i++) {
        if (!(sum % i)) {
            prime = 0;
            break;
        }
    }
    if (prime) answer++;
    return;
}

void dfs(vector<int>& nums, int level) {
    if (level == 3) {
        int sum = 0;
        for (int i = 0; i < level; i++) {
            sum += path[i];
        }
        isPrime(sum);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (visited[i] == 1) continue;
        if (path[level - 1] >= nums[i]) continue;
        visited[i] = 1;
        path[level] = nums[i];
        dfs(nums, level + 1);
        path[level] = 0;
        visited[i] = 0;
    }
    return;
}

int solution(vector<int> nums) {
    dfs(nums, 0);
    return answer;
}

int main() {
    vector<int> nums = { 1, 2, 3, 4 };
    int result = solution(nums);
    cout << result;
    return 0;
}