#include <bits/stdc++.h>

using namespace std;

int before[30][30], after[30][30], dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}, N, M;

int DFS(int x, int y, int change_val, int fill_val) {
	int i, j, k, l, nx, ny;
	before[y][x] = fill_val;
	for (i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i];
		if (nx == -1 || nx == M || ny == -1 || ny == N) continue;
		if (before[ny][nx] != change_val) continue;
		DFS(nx, ny, change_val, fill_val);
	}
	return 1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, con = 0;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> before[i][j];
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> after[i][j];
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (before[i][j] != after[i][j]) {
				if (con) {
					cout << "NO" << "\n";
					return 0;
				}
				DFS(j, i, before[i][j], after[i][j]);
				con = 1;
			}
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (before[i][j] != after[i][j]) {
				if (con) {
					cout << "NO" << "\n";
					return 0;
				}
				DFS(j, i, before[i][j], after[i][j]);
				con = 1;
			}
		}
	}
	cout << "YES" << "\n";
	return 0;
}