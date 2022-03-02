#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int ropes[100000];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", &ropes[i]);
	sort(ropes, ropes+N, greater<>());
	int maxi = 0;
	for (int i = 0; i < N; ++i) {
		int cnt = i + 1; // stronger ropes that can withstand the weight
		maxi = max(maxi, ropes[i] * cnt);
	}
	printf("%d", maxi);
}