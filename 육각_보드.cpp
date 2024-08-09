#include <bits/stdc++.h>

using namespace std;
vector<string> a(50);
int graph[50][50], visited[50][50], dx[6] = {0, 1, -1, 1, -1, 0}, dy[6] = {-1, -1, 0, 0, 1, 1}, N;

int dfs(int y, int x, int val) {
	int i, j, k, l, nx, ny, cnt = 1;
	if (visited[y][x]) {
		return 0;
	}
	graph[y][x] = val;
	visited[y][x] = 1;
	for (i = 0; i < 6; i++) {
		nx = dx[i] + x, ny = dy[i] + y;
		if (nx < 0 || ny < 0 || ny == N || nx == N) continue;
		if (graph[ny][nx] == val) {
			cout << 3 << "\n";
			exit(0);
		}
		if (a[ny][nx] == 'X' && !visited[ny][nx]) {
			dfs(ny, nx, (val + 1) % 2);
			cnt = 2;
		} else {
			visited[ny][nx] = 1;
		}
	}
	return cnt;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	queue<pair<int, int>> Q;
	int i, j, k, l, result = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
		fill(graph[i], graph[i] + 50, -1);
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (graph[i][j] == -1 && !visited[i][j] && a[i][j] == 'X') result = max(dfs(i, j, 0), result);
		}
	}

	cout << result << "\n";

	return 0;
}