#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, result = 0, iter_break;
	cin >> N >> M;
	vector<vector<int>> now(N, vector<int>(M, 0)), next;
	queue<pair<int, int>> DQ;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> now[i][j];
			if (i == N - 1 || j == M - 1 || i == 0 || j == 0) DQ.push({j, i});
		}
	}
	now = next;
	while (1) {
		now = next;
		iter_break = 0;
		while (DQ.size()) {
			int x, y;
			tie(x, y) = DQ.front();
			DQ.pop();
			if (now[y][x]) continue;
			now[y][x] = -1;
			for (i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx == -1 || ny == -1 || nx == M || ny == N) continue;
				if (now[ny][nx] == 0) {
					DQ.push({nx, ny});
				}
			}
		}
		next = now;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				int iter = 0;
				iter_break += (now[i][j] == 1);
				if (now[i][j] != 1) continue;
				for (k = 0; k < 4; k++) {
					int nx = j + dx[k], ny = i + dy[k];
					if (nx == -1 || ny == -1 || nx == M || ny == N) {
						iter++;
						continue;
					}
					iter += (now[ny][nx] == -1);
				}
				if (iter >= 2) {
					next[i][j] = 0;
					now[i][j] = 0;
					DQ.push({j, i});
				}
			}
		}
		if (iter_break) {
			result++;
		} else
			break;
	}
	cout << result << "\n";

	return 0;
}