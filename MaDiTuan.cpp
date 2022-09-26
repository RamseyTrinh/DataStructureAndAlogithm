#include<iostream>
using namespace std;

// bài toán mã đi tuần: đi hết ô bàn cờ vua nxn, mỗi ô đi đúng 1 lần
// độ rộng bàn cờ càng lớn thì chạy càng lâu

int n;
int a[10][10];

int StepX[9] = { 0,-1,-2,-2,-1,1,2,2,1 };
int StepY[9] = { 0,-2,-1,1,2,2,1,-1,-2 };

void khoitao() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = 0;
		}
	}
}

bool check(int x, int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

int step = 0;
void move(int x, int y) {
	a[x][y] = ++step;
	for (int i = 1; i <= 8; i++) {
		if (step == n * n) {
			print();
			exit(0);
		}
		int NewX = x + StepX[i];
		int NewY = y + StepY[i];
		if (check(NewX, NewY) && a[NewX][NewY] == 0) {
			move(NewX, NewY);
		}
	}
	step--;
	a[x][y] = 0;
}

int main() {
	cout << "Type board length (NxN): ";
	cin >> n;
	int x, y;
	cout << "Coordinate (x,y starts from 1 to N): ";
	cin >> x >> y;
	move(x, y);
	cout << "There's no way to go";
	return 0;
}