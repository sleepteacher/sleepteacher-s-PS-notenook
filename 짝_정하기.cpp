#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int data[3][2], data[3][2];
	int i, j, k, l, result, N;
	cin >> N;
	for (i = 0; i < 3; i++) {
		cin >> origin[i][0] >> origin[i][1];
		if (origin[i][1] > N - origin[i][0]) {
			cout << 0;
			exit(0);
		}
	}
	cout << 1 << "\n";
	for (i = 0; i < 3; i++) {
		result = 0;
		for (j = 0; j < 3; j++) {
			if (j == i) continue;
			if (origin[i][0] <= origin[j][1]) {
				cout << origin[i][0] << " ";
				origin[j][1] -= origin[i][0];
			} else {
				cout << origin[j][1] << " ";
				origin[i][0] -= origin[j][1];
				result = origin[j][1];
				origin[j][1] = 0;
			}
		}
		cout << "\n";
	}

	return 0;
}