#include<iostream>
using namespace std;

int N;
int num[50];
int path[5];
int used[51];
int buf[3000] = { 0 };
int cnt = 0;

int PrimeCheck(int n) {
 
    for (int i = 2; i <= n; i++) {
        if (i * i > n) { break; }
        if (n % i == 0) { return 0; }
    }
    return 1;
}

void dfs(int level) {
    if (level == 3) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += path[i];
        }
        int flag = PrimeCheck(sum);
        if (flag == 1) { buf[sum]++; }
        return;
    }
    for (int i = 0; i < N; i++) {
        if (used[i] == 1) continue;
        used[i] = 1;
        path[level] = num[i];
        dfs(level + 1);
        path[level] = 0;
        used[i] = 0;
    }
}
int main()
{
    //입력 N=입력개수, num[]입력 순서대로
    cin >> N;
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        cin >> num[tmp++];
    }
    dfs(0);
    
    for (int i = 0; i < 3000; i++) {
        if (buf[i] > 0) { cnt++; }
    }
    cout << cnt;
    
    return 0;
}