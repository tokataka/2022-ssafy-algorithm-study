#define #_CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

// yellow = a*b
// brown = (a+2)*(b+2)-yellow = 2(a+b)+4 

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size = brown + yellow;
    vector<pair<int, int>>v;
    for (int i = 3; i < size / 2; ++i) {
        if (size % i != 0) continue;
        v.push_back(make_pair(i, size / i));
    }
    for (int i = 0; i < v.size(); ++i) {
        int cr = v[i].first;
        int cc = v[i].second;
        if (2 * (cr + cc) - 4 == brown - yellow) {
            if (cc <= cr) {
                answer.push_back(cr);
                answer.push_back(cc);
            }
            else {
                answer.push_back(cc);
                answer.push_back(cr);
            }
            break;
        }
    }
    return answer;
}