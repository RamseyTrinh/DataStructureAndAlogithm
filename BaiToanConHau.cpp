#include<iostream>  
using namespace std;

bool a[10][10];
bool checkdong[10][10];
bool checkcheolen[10][10];
bool checkcheoduoi[10][10];

void show() {
    for(int i = 1; i <= 8; i++) {
        for(int j = 1; j <= 8; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void check(int i, int j) {
    for(int k = 1; k <= 8; k++) {
        checkdong[i][k] = 1;
    }
    int x = i, y = j;
    while(x >= 1 && y <= 8) {
        checkcheolen[x][y] = 1;
        x--;
        y++;
    }
    x = i;
    y = j;
    while(x <= 8 && y <= 8) {
        checkcheoduoi[x][y] = 1;
        x++;
        y++;
    }
}

void reset(int i, int j) {
    for(int k = 1; k <= 8; k++) {
        checkdong[i][k] = 0;
    }
    int x = i, y = j;
    while(x >= 1 && y <= 8) {
        checkcheolen[x][y] = 0;
        x--;
        y++;
    }
    x = i;
    y = j;
    while(x <= 8 && y <= 8) {
        checkcheoduoi[x][y] = 0;
        x++;
        y++;
    }
}

void tinh(int i) {
    if(i == 8) {
        show();
        return;
    } else {
        for(int j = 1; j <= 8; j++) {
            if(!checkdong[j][i+1] && !checkcheoduoi[j][i+1] && !checkcheolen[j][i+1]) {
                check(j,i+1);
                a[j][i+1] = 1;
                tinh(i+1);
                a[j][i+1] = 0;
                reset(j,i+1);
            }
        }
    }
}

int main() {
    for(int i = 1; i <= 8; i++) {
        a[i][1] = 1;
        check(i,1);
        tinh(1);
        a[i][1] = 0;
        reset(i,1);
    }
    return 0;
}