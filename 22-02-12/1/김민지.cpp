#include<stdio.h>
#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

int solution(string begin, string target, vector<string>words) {
	bool isexist = false;
	for (vector<string>::iterator iter = words.begin(); iter != words.end(); ++iter) {
		if (*iter == target) {
			isexist = true;
			break;
		}
	}
	if (!isexist) return 0;
	queue<pair<string, int>>q;
	q.push({ begin, 0 });
	unordered_map<string, bool>visited;
	visited.insert({ begin, true });
	while (!q.empty()) {
		string cur = q.front().first;
		int times = q.front().second;
		q.pop();
		if (cur == target) { return times; }

		for (int i = 0; i < words.size(); ++i) {
			if (words[i].length() != cur.length()) continue;
			int differences = 0;
			string compare = words[i];
			for (int j = 0; j < compare.length(); ++j) {
				if (compare[j] != cur[j]) {
					++differences;
					if (differences == 2) break;
				}
			}
			if (differences == 1) {
				if (visited.count(compare) == 0) {
					visited.insert({ compare, true });
					q.push({ compare, times + 1 });
				}
			}
		}
	}
	return 0;
}