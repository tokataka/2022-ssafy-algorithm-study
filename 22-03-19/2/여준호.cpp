#include <iostream>
#include <queue>
using namespace std;

int ans[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> Maxh;
	priority_queue<int, vector<int>, greater<int>> Minh;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (Maxh.size() == Minh.size()) { Maxh.push(a); }
		else if(Maxh.size()>Minh.size()){ Minh.push(a); }

		if (i == 0) { 
			ans[i] = Maxh.top();
			continue;
		}

		int tmp1 = Maxh.top();
		int tmp2 = Minh.top();
		if (tmp1>tmp2) {
			Maxh.pop();
			Minh.pop();

			Maxh.push(tmp2);
			Minh.push(tmp1);
		}

		ans[i] = Maxh.top();
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i]<<"\n";
	}
	return 0;
}