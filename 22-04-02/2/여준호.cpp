#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int vect[100][2];
priority_queue<int, vector<int>, greater<int>> package;
priority_queue<int, vector<int>, greater<int>> per;


void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		package.push(a);
		per.push(b);
	}
}

int main()
{
	input();

	int tmp1, tmp2, tmp3;
	tmp1 = N * (per.top());
	tmp2 = ((N / 6) + 1)*(package.top());
	tmp3 = (N / 6)*package.top() + (N % 6)*per.top();

	int ans = min(tmp1, tmp2);
	ans = min(ans, tmp3);
	cout << ans;
	
	return 0;
}