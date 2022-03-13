#include<iostream>
#include<vector>

using namespace std;

int arr[40000];
vector<int> result;

void binarysearch(int left, int right, int n) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (result[mid] < n) left = mid + 1;
		else if (result[mid] > n) right = mid - 1;
		else {
			result[mid] = n;
			return;
		}
	}
	result[left] = n;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	result.push_back(arr[0]);
	int index = 0;
	for (int i = 1; i < n; i++) {
		if (result[index] < arr[i]) {
			index++;
			result.push_back(arr[i]);
		}
		else {
			binarysearch(0, index, arr[i]);
		}
	}
	cout << result.size();
	return 0;
}