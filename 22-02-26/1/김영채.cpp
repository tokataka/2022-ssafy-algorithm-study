#include<iostream>
#include<string>
#include<vector>

using namespace std;

int N;
int arr[11];
int cal[4];
int mini = 10e10;
int maxi = -10e10;
int result;
vector<int> path;

void dfs(int level) {
	if (level == N - 1) {
		for (int i = 0; i < path.size(); i++) {
			if (path[i] == 0) result += arr[i + 1];
			else if (path[i] == 1) result -= arr[i + 1];
			else if (path[i] == 2) result *= arr[i + 1];
			else if (path[i] == 3) result /= arr[i + 1];
		}
		if (maxi < result) maxi = result;
		if (mini > result) mini = result;
		result = arr[0];
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!cal[i]) continue;
		path.push_back(i);
		cal[i]--;
		dfs(level + 1);
		cal[i]++;
		path.pop_back();
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> cal[i];
	}
	result = arr[0];
	dfs(0);
	cout << maxi << endl << mini;
	return 0;
}