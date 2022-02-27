//https://www.acmicpc.net/problem/1343
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

string answer;

bool check(string sub) {
	int length = sub.length();
	if (length % 2 != 0) return false;
	if (length % 4 == 0) {
		for (int i = 0; i < length / 4; ++i) answer += "AAAA";
		return true;
	}
	while (length >= 4) {
		answer += "AAAA";
		length -= 4;
	}
	if (length == 2) answer += "BB";
	return true;
}

int main() {
	char s[51];
	cin >> s;
	int index = 0;
	answer = "";
	string sub = "";
	bool fail = false;
	while (s[index] != '\0') {
		if (s[index] == '.') {
			if (sub != "") {
				bool result = check(sub);
				if (!result) {
					fail = true;
					break;
				}
				sub = "";
			}
			answer += ".";
		} else if (s[index] == 'X') sub += "X";
		++index;
	}
	if (sub != "") {
		bool result = check(sub);
		if (!result) fail = true;
	}
	if (fail) answer = "-1";
	cout << answer;
}