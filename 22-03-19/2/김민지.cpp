#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;
int arr[100001];

int main() {
	scanf("%d", &N);
	priority_queue<int>maxHeap; // top is the mid value, ~ mid
	priority_queue<int, vector<int>, greater<int>>minHeap; // mid ~
	int num;
	scanf("%d", &num);
	maxHeap.push(num); // initialize the mid value
	printf("%d\n", maxHeap.top());
	for (int i = 1; i < N; ++i) {
		scanf("%d", &num);
		if (maxHeap.size() == minHeap.size()) maxHeap.push(num);
		else minHeap.push(num);
		
		if (maxHeap.size() != 0 && minHeap.size() != 0 && maxHeap.top() > minHeap.top()) {
			int maxi = maxHeap.top();
			int mini = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(mini);
			minHeap.push(maxi);
		}
		printf("%d\n", maxHeap.top());
	}
}