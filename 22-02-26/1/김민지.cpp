#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int N, maxi, mini;
vector<int>numbers;
vector<int>operators(4);

void dfs(int result, int lv) {
	if (lv == N) {
		mini = min(mini, result);
		maxi = max(maxi, result);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (operators[i] != 0) {
			--operators[i];
			if (i == 0) dfs(result + numbers[lv], lv + 1);
			else if (i == 1) dfs(result - numbers[lv], lv + 1);
			else if (i == 2) dfs(result * numbers[lv], lv + 1);
			else if (i == 3) dfs(result / numbers[lv], lv + 1);
			++operators[i];
		}
	}
}

int main() {
	scanf("%d", &N);
	maxi = -1000000000;
	mini = 1000000000;
	for (int i = 0; i < N; ++i) {
		int number;
		scanf("%d", &number);
		numbers.push_back(number);
	}
	for (int i = 0; i < 4; ++i) {
		int op;
		scanf("%d", &op);
		operators[i] = op;
	}
	dfs(numbers[0], 1);
	printf("%d\n", maxi);
	printf("%d\n", mini);
}