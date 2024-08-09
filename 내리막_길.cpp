#include <bits/stdc++.h>

using namespace std;

int graph[501][501], dp[501][501];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1}, N, M;

int dfs(int x, int y) {
	int nx, ny, val;
	if (dp[y][x]) return dp[y][x];
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i], ny = y + dy[i];
		if (nx == -1 || nx == M || ny == -1 || ny == N) continue;
		if (graph[y][x] <= graph[ny][nx]) continue;
		val = dfs(nx, ny);
		if (val == -1)
			continue;
		else
			dp[y][x] += val;
	}
	dp[y][x] = dp[y][x] == 0 ? -1 : dp[y][x];
	return dp[y][x];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	dp[N - 1][M - 1]++;
	cout << max(dfs(0, 0), 0) << "\n";

	return 0;
}