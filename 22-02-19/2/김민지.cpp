#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int>a(n);
	vector<int>b(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	priority_queue<pair<int, int>>pq;
	// 1. b의 원소들을 오름차순으로 정렬
	// 2. a는 내림차순으로 정렬 
	// 3. 같은 index에 있는 원소들끼리 곱하면 최소값
	sort(a.begin(), a.end()); // 오름차순
	sort(b.begin(), b.end(), greater<int>()); // 내림차순
	int s = 0;
	for (int i = 0; i < n; ++i) s += (a[i] * b[i]);
	printf("%d", s);
}
