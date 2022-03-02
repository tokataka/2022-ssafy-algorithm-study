#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	//입력
	int N;
	cin >> N;
	vector <int> arr;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}
	
	//오름차순 정렬
	sort(arr.begin(), arr.end());

	//최대값 구하기
	int max = 0;
	for (int i = 0; i < N; i++) {
		int sum = (N - i)*arr[i];
		if (sum > max) { max = sum; }
	}
	cout << max;
	return 0;
}