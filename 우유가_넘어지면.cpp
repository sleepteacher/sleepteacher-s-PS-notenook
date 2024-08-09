#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M;
	vector<string> arr;
	string input;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}
	for (i = M - 1; i != -1; i--) {
		for (j = 0; j < N; j++) {
			switch (arr[j][i]) {
				case 46:
					cout << ".";
					break;
				case 79:
					cout << "O";
					break;
				case 45:
					cout << "|";
					break;
				case 124:
					cout << "-";
					break;
				case 47:
					cout << "\\";
					break;
				case 92:
					cout << "/";
					break;
				case 94:
					cout << "<";
					break;
				case 60:
					cout << "v";
					break;
				case 118:
					cout << ">";
					break;
				case 62:
					cout << "^";
					break;
				default:
					break;
			}
		}
		cout << "\n";
	}
	return 0;
}