#include<iostream>
#include<string.h>
using namespace std;

void chuyen(int n, char a, char b, char c) {
	if(n == 1) {
		cout << a << " => " << c << "\n";
	} else {
		chuyen(n-1,a,c,b);
		cout << a << " => " << c << "\n";
		chuyen(n-1,b,a,c);
	}
} 

int main () {
	int n;
	cout << "Nhap so dia cua thap: ";
	cin >> n;
	char a = 'a', b = 'b', c = 'c';
	chuyen(n,a,b,c);
	return 0;
}
