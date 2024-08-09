#include <bits/stdc++.h>

using namespace std;

int out(stack<int> num, stack<char> giho, bool front_giho,int front) {
	int a = num.top(), b, c = a;
	char tmp = giho.top();
	num.pop();
	b = num.top();
	switch (giho.top()) {
		case '+':
			c += b;
			break;
		case '-':
			c -= b;
			break;
		case '*':
			c *= b;
			break;
		case '/':
			c /= b;
			break;
		default:
			break;
	}
	num.pop(), giho.pop();

	while (num.size()) {
		switch (giho.top()) {
			case '+':
				a += b;
				break;
			case '-':
				a -= b;
				break;
			case '*':
				a *= b;
				break;
			case '/':
				a /= b;
				break;
			default:
				break;
		}
		cout << a;
		num.pop();
		//giho.pop();
		b = num.top();
	}
	return a;
}

/*
3+8*7-9*2
68*2

(1-9)-(1-9)-(1-9)-(1-9)-(1-9)
24

8*
3+5+2
(8*3)
+5+2
19
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
*/

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N;
	stack<int> num;
	stack<char> giho;
	string in;
	cin >> N >> in;
	for (i = 0; i < in.size(); i++) {
		if ('0' <= in[i] && in[i] <= '9') {
			num.push(in[i] - '0');
		} else {
			giho.push(in[i]);
		}
	}
	cout << out(num, giho, 0, 0);

	return 0;
}