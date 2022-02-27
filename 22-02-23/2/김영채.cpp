#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    int height = 3;
    while (1) {
        if (!(sum % height)) {
            int length = sum / height;
            if (((height - 2) * (length - 2)) == yellow) {
                answer.push_back(length);
                answer.push_back(height);
                break;
            }
        }
        height++;
    }
    return answer;
}