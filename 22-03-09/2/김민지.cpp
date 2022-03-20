//#include<iostream>
//#include<stdio.h>
//#include<vector>
//
//using namespace std;
//
//vector<int>v;
//int N;
//
//int binarySearch(int target) {
//	int left = 0;
//	int right = v.size();
//	int mid;
//	while (true) {
//		mid = left + right / 2;
//		if (v[mid] >= target) right = mid;
//		else if (v[mid] < target) left = mid + 1;
//	}
//	return left;
//}
//
//int main() {
//	cin >> N;
//	int idx = 0;
//	
//	for (int i = 0; i < N; ++i) {
//		int target;
//		cin >> target;
//		if (i == 0) {
//			v.push_back(target);
//			continue;
//		}
//		if (v[idx] < target) {
//			v.push_back(target);
//			++idx;
//		}
//		else {
//			int next = binarySearch(target);
//			v[next] = target;
//		}
//	}
//	int answer = v.size();
//	printf("%d", answer);
//}