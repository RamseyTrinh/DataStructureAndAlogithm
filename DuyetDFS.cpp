#include<iostream>  
#include<fstream>
#include<vector>
#define Max 1000
using namespace std;

vector<int>a[1000];
bool check[1000] = {0};

// Duyệt từ đỉnh thứ start.
void DuyetDFS(int start) {
    cout << "Da di qua dinh thu: " << start << "\n";
    check[start] = 1;
    for(int i = 0; i < a[start].size(); i++) {
        if(check[a[start][i]] == 0) {
            DuyetDFS(a[start][i]);
        }
    }
}

int main() {
    freopen("Duyet_BFS-DFS.txt","r",stdin);
    int corner;    
    cin >> corner;
    int edge;
    cin >> edge;
    for(int i = 0; i < edge; i++) {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    // for(int i = 1; i <= corner; i++) {
    //     cout << i << " : ";
    //     for(int j = 0; j < a[i].size(); j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    DuyetDFS(4);
    return 0;
}
 