#include<iostream>
#include<queue>
#include<fstream>
using namespace std;

vector<int>a[1000];
bool check[1000] = {0};

void DuyetBFS(int start) {
    queue<int>tmp;
    tmp.push(start);
    while(!tmp.empty()) {
        int v = tmp.front();
        cout << "Da di qua dinh thu " << v << "\n";
        check[v] = 1;
        tmp.pop();
        for(int i = 0; i < a[v].size(); i++) {
            if(check[a[v][i]] == 0) {
                tmp.push(a[v][i]);
                check[a[v][i]] = 1;
            }
        }
    }
}

int main()
{
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
    DuyetBFS(1);
}