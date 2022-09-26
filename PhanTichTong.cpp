#include <bits/stdc++.h>
using namespace std;

vector<int>a;

void xuat(int n) {
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void tinh(int n, int i) {
    if(n == 0) {
        for(int j = 1; j <= i; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
    } else {
        for(int x = a[i] + 1; x <= n; x++) {
            a.push_back(x);
            tinh(n-x,i+1);
            a.pop_back();
        }
    }
}


int main() {
    int n;
    cin >> n;
    a.push_back(0);
    tinh(n,0);
    return 0;
}