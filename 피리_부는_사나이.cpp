#include <bits/stdc++.h>

using namespace std;

int N, M, Mgraph[1000][1000], graph[1000][1000], dy[4] = {0, 0, -1, 1}, dx[4] = {1, -1, 0, 0};

int DFS(int x, int y, int val) {
	int cnt = Mgraph[y][x], nx = x + dx[cnt], ny = y + dy[cnt];
	if (nx == -1 || ny == -1 || nx == M || ny == N || graph[ny][nx] == val) {
		graph[y][x] = val;
		return 0;
	}
	if (graph[ny][nx] == 0) {
		graph[y][x] = val;
		DFS(nx, ny, val);
	}
	graph[y][x] = graph[ny][nx];
	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, result = 0;
	char in;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> in;
			switch (in) {
				case 'R':
					Mgraph[i][j] = 0;
					break;
				case 'L':
					Mgraph[i][j] = 1;
					break;
				case 'U':
					Mgraph[i][j] = 2;
					break;
				case 'D':
					Mgraph[i][j] = 3;
					break;
				default:
					break;
			}
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (!graph[i][j]) {
				DFS(j, i, ++result);
				if (result != graph[i][j]) result--;
			}
		}
	}

	cout << result;
	return 0;
}