#include <iostream>
using namespace std;

char vect[10][10];

void change(int y, int x,int b,int a) {
    
    int ay[4] = { 0,1,0,-1 };
    int ax[4] = { 1,0,-1,0 };
    
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int dy = y + ay[i];
        int dx = x + ax[i];
        if (dy < 0 || dx < 0 || dy >= b || dx >= a) { 
            cnt++;
            continue;
        }
        if (vect[dy][dx] == '.') { cnt++; }
        if (cnt >= 3) { 
            vect[y][x] = 'o';
            return;
        }
    }
}

int main()
{
    int a, b;
    cin >> b >> a;

    for (int y = 0; y < b; y++) {
        cin >> vect[y];
    }

    for (int y = 0; y < b; y++) {
        for (int x = 0; x < a; x++) {
            if(vect[y][x]=='X'){ change(y, x, b, a); }
        }
    }
    int minx = 100;
    int miny = 100;
    int maxx = 0;
    int maxy = 0;
    for (int y = 0; y < b; y++) {
        for (int x = 0; x < a; x++) {
            if (vect[y][x] == 'o') { vect[y][x]='.'; }
            if (vect[y][x] == 'X') {
                if (miny > y) { miny = y; }
                if (maxy < y) { maxy = y; }
                if (minx > x) { minx = x; }
                if (maxx < x) { maxx = x; }
            }
        }
    }
    for (int y = miny; y <= maxy; y++) {
        for (int x = minx; x <= maxx; x++) {
            cout << vect[y][x];
        }
        cout << endl;
    }

    return 0;
}