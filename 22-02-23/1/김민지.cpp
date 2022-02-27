#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<stdio.h>
#include<queue>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>>v(N + 1);
	int days[16] = { 0 };
	int payments[16] = { 0 };
	for (int i = 1; i <= N; ++i) {
		int day, payment;
		scanf("%d %d", &day, &payment);
		days[i] = day;
		payments[i] = payment;
	}
	int valid[16] = { 0 };
	for (int i = 1; i <= N; ++i) {
		if (days[i] + i - 1 > N) continue;
		valid[i] = 1;
	}
	int answer = 0;
	int daily[16] = { 0 };
	for (int i = N; 0 < i; --i) {
		if (valid[i] == 0) daily[i] = daily[i + 1]; // unavailable today, 
		else {
			daily[i] = max(daily[i + days[i]] + payments[i], daily[i + 1]); // today or tomorrow
		}
	}
	printf("%d", daily[1]);
}