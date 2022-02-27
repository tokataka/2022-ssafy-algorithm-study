#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

bool check(int sum) {
	for (int i = 2; i < sum / 2; ++i) {
		if (sum % i == 0) return false;
	}
	return true;
}

int solution(vector<int> nums) {
	int sum = 0;
	int answer = 0;
	unordered_map<int, bool>isPrime;
	for (int i = 0; i < nums.size() - 2; ++i) {
		sum += nums[i];
		for (int j = i + 1; j < nums.size() - 1; ++j) {
			sum += nums[j];
			for (int k = j + 1; k < nums.size(); ++k) {
				sum += nums[k];
				if (isPrime.count(sum) == 0) {
					bool result = check(sum);
					if (result) {
						++answer;
						isPrime.insert({ sum, true });
					}
					else {
						isPrime.insert({ sum, false });
					}
				}
				else {
					if (isPrime[sum]) ++answer;
				}
				sum -= nums[k];
			}
			sum -= nums[j];
		}
		sum -= nums[i];
	}
	return answer;
}