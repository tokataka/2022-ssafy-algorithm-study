#include <iostream>

using namespace std;

int main() {
    int R, C;
    char arr[10][10];
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    int direct[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (arr[y][x] == 'X') {
                int cnt = 0;
                for (int i = 0; i < 4; i++) {
                    int iny = y + direct[i][0];
                    int inx = x + direct[i][1];
                    if (iny < 0 || inx < 0 || iny >= R || inx >= C) {
                        cnt++;
                        continue;
                    }
                    if (arr[iny][inx] == '.') cnt++;
                }
                if (cnt >= 3) arr[y][x] = '&';
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == '&') arr[i][j] = '.';
        }
    }

    int starty = 99;
    int endy = 0;
    int startx = 99;
    int endx = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j] == 'X') {
                if (j > endx) endx = j;
                if (i > endy) endy = i;
                if (j < startx) startx = j;
                if (i < starty) starty = i;
            }
        }
    }
    

    for (int i = starty; i <= endy; i++) {
        for (int j = startx; j <=endx; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}