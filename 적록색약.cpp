#include <bits/stdc++.h>

using namespace std;
char graph[100][100];
bool visited[100][100];
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0}, N;

int NDFS(int x, int y) {
	if (!visited[x][y]) {
		visited[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx == N || ny < 0 || ny == N || visited[nx][ny]) continue;
			if (graph[x][y] == graph[nx][ny]) {
				NDFS(nx, ny);
			}
		}
		return 1;
	}
	return 0;
}
int SDFS(int x, int y) {
	if (!visited[x][y]) {
		visited[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx == N || ny < 0 || ny == N || visited[nx][ny]) continue;
			if ((graph[x][y] == 'R' || graph[x][y] == 'G') && (graph[nx][ny] == 'R' || graph[nx][ny] == 'G')) {
				SDFS(nx, ny);
			}
			if (graph[x][y] == graph[nx][ny] && !visited[nx][ny]) {
				SDFS(nx, ny);
			}
		}
		return 1;
	}
	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, result = 0;
	cin >> N;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) cin >> graph[i][j];

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) result += NDFS(i, j);
	cout << result << " ";
	result = 0;
	for (i = 0; i < N; i++) fill(visited[i], visited[i] + N, 0);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) result += SDFS(i, j);
	cout << result << "\n";

	return 0;
}