#include<iostream>
using namespace std;

int a[1000];
int n;

void show() {
    for(int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << endl;
}

bool check[100] = {0};
void BackTrackToHopSoTuNhien(int i) {
    if(i == n) {
        show();
    } else {
        for(int j = 1; j <= n; j++) {
            if(check[j] == 0) {
                a[i+1] = j;
                check[j] = 1;
                BackTrackToHopSoTuNhien(i+1);
                check[j] = 0;
            }
        }
        
    }
}

void BackTrackNhiPhan(int i) {
    if(i == n) {
        show();
    } else {
        a[i+1] = 0;
        BackTrackNhiPhan(i+1);
        a[i+1] = 1;
        BackTrackNhiPhan(i+1);
    }
}

int main() {
    cin >> n;
    BackTrackToHopSoTuNhien(0);
    BackTrackNhiPhan(0);
    return 0;
}