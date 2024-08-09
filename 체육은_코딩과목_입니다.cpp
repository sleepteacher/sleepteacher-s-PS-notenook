#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, con = 0;
	// 북 0 서 1 남 2 동 3
	for (i = 0; i < 10; i++) {
		cin >> j;
		if (j == 1) {
			con = (con + 3) % 4;
		} else if (j == 2) {
			con = (con + 2) % 4;
		} else {
			con = (con + 1) % 4;
		}
	}
	if (con == 0) {
		cout << "N";
	} else if (con == 1) {
		cout << "W";
	} else if (con == 2) {
		cout << "S";
	} else if (con == 3) {
		cout << "E";
	}

	return 0;
}