#include <bits/stdc++.h>

using namespace std;

int x_arr[9], y_arr[9], z_arr[9], con;
long long iter = 0;
string arr[9];
/*
1 2 3
4 5 6
7 8 9
*/

void DFS(int x, int y, int depth) {
	if (con) return;
	if (depth == 81) {
		con++;
		int i, j, k, l;
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		return;
	}
	int data = arr[y][x] - '0', i, j, k, l;
	if (data == 0) {
		for (i = 1; i <= 9; i++) {
			if (con) return;
			if (((x_arr[x] | 1 << i) != x_arr[x]) && ((y_arr[y] | 1 << i) != y_arr[y]) && ((z_arr[y / 3 * 3 + x / 3] | 1 << i) != z_arr[y / 3 * 3 + x / 3])) {
				x_arr[x] += 1 << i;
				y_arr[y] += 1 << i;
				z_arr[y / 3 * 3 + x / 3] += 1 << i;
				arr[y][x] = '0' + i;
				DFS((x + 1) % 9, (x + 1) / 9 + y, depth + 1);
				arr[y][x] = '0';
				x_arr[x] -= 1 << i;
				y_arr[y] -= 1 << i;
				z_arr[y / 3 * 3 + x / 3] -= 1 << i;
			}
		}
	} else {
		DFS((x + 1) % 9, (x + 1) / 9 + y, depth + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			int data = arr[i][j] - '0';
			if (data) {
				x_arr[j] += 1 << data;
				y_arr[i] += 1 << data;
				z_arr[(i / 3) * 3 + j / 3] += 1 << data;
			}
		}
	}
	DFS(0, 0, 0);

	return 0;
}