#include <bits/stdc++.h>

using namespace std;

bool visited[100][70];
int graph[100][70], N, M, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int DFS(int x, int y) {
	if (!visited[y][x]) {
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l,result = 0;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (!visited[i][j]) {
				int con = 0;
				for (k = 0; k < 4; i++) {
					int nx = dx[i] + j, ny = dy[i] + i;
					if (nx < 0 || ny < 0 || nx == M || ny == N) continue;
					if (graph[i][j] < graph[ny][nx]) con++;
				}
				if (!con) {
					result++;
                    DFS(j, i);
				}
					
			}
		}
	}
	return 0;
}