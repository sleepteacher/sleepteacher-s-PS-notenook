#include <bits/stdc++.h>

using namespace std;

int graph[1000][1000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, result = 0, con, max_size, a, b, c;
	string in;
	queue<pair<int, int>> Q, TP;
	// 길이/깊이 반복/
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> in;
		for (j = 0; j < M; j++) {
			graph[i][j] = in[j] - '0';
			if (j && graph[i][j]) {
				graph[i][j] += graph[i][j - 1];
			}
		}
	}
	for (i = 0; i < M; i++) {
		max_size = i + 1;
		con = 1;
		for (j = 0; j < N; j++) {
			while (Q.size()) {
				tie(a, b) = Q.front();
				Q.pop();
				if (max(graph[j][i], max_size) < b) {
				} else if (max(graph[j][i], max_size) == b) {
				} else {
				}
			}
		}
	}
	cout << result * result;

	return 0;
}