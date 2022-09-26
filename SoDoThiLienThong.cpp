#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;

vector<int>a[10000];
bool check[1000] = {0};

void BFS(int start) {
    queue<int>res;
    res.push(start);
    while(!res.empty()) {
        int v = res.front();
        cout << v << " ";
        check[v] = 1;
        res.pop();
        for(int i = 0; i < a[v].size(); i++) {
            if(check[a[v][i]] == 0) {
                res.push(a[v][i]);
                check[a[v][i]] = 1;
            }
        }
    }
}

int main() {
    freopen("SoDoThiLienThong.txt","r",stdin);
    int corner, edge;
    cin >> corner >> edge;
    for(int i = 0; i < edge; i++) {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    int SoLienThong = 0;
    for(int i = 1; i <= corner; i++) {
        if(check[i] == 0) {
            SoLienThong++;
            cout << "Cac do thi trong lien thong " << SoLienThong << " la: ";
            BFS(i);
            cout << endl;
        }
    }
    return 0;
}