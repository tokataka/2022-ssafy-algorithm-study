#include <iostream>
#include <string>
using namespace std;

string input;

void change(int a, int b) {
	int sub = b-a;
	if (sub % 4 == 0) {
		for (int i = a; i < b; i++) {
			input[i] = 'A';
		}
	}
	else if (sub % 4 == 2) {
		if (sub / 4 == 0) {
			for (int i = a; i < b; i++) {
				input[i] = 'B';
			}
		}
		else {
			for (int i = a; i < b-2; i++) {
				input[i] = 'A';
			}
			for (int i = b - 2; i < b; i++) {
				input[i] = 'B';
			}
		}
	}
}

int main()
{
	//입력
	cin >> input;

	//
	int sPos = 0;
	while (1)
	{
		int findPos = input.find(".", sPos);
		if (findPos == input.npos) {
			if (sPos == 0 && input.size() % 2 == 1) {
				cout << -1;
				return 0;
			}
			findPos = input.size();
			change(sPos, findPos);
			break;
		}
		if ((findPos - sPos) % 2 == 1) {
			cout << -1;
			return 0;
		}
		change(sPos, findPos);
		int lastPos = 0;
		for (lastPos = findPos + 1; lastPos < input.size(); lastPos++) {
			if (input[lastPos] != '.') { break; }
		}

		sPos = lastPos;
	}
	cout << input;
	return 0;
}