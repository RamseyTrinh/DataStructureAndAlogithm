#include<iostream>
#include<stack>
using namespace std;

int Prior(char s) {
	if (s == '+' || s == '-') {
		return 1;
	}
	if (s == '*' || s == '/') {
		return 2;
	}
	if (s == '^') {
		return 3;
	}
	return 0;
}

int main() {
	stack<char>s;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			cout << str[i];
		}
		else {
			if (str[i] == '(') {
				s.push(str[i]);
			}
			else if (str[i] == ')') {
				while (s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.pop();
			}
			else {
				while (!s.empty() && Prior(str[i]) <= Prior(s.top())) {
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
			}	
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}