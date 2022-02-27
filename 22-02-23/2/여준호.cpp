#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
    int brown;
    int yellow;
    cin >> brown >> yellow;
    //brown == 2(가로+세로+2), yellow = 가로*세로

    int garo=1, sero=1;
    for (int i = 1; i < yellow; i++) {

        // (제곱근보다 작을때까지만) 세로길이 < 가로길이
        if (i*i > yellow) { break; }

        // 1부터 쭉 일일이 나눠보고 나눠지는 경우 
        if (yellow%i == 0) {
            garo = yellow / i;
            sero = i;
            
            //가로 세로 구해졌을 경우 brown값 테스트
            if (brown == 2 * (garo + sero + 2)) {
                break;
            }
        }
    }
    //큰 직사각형의 가로 세로
    int big_garo = garo + 2;
    int big_sero = sero + 2;

    cout << "[" << big_garo << "," << big_sero << "]";
    return 0;
}