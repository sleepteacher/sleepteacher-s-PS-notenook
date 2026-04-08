#include <bits/stdc++.h>

using namespace std;
#define INF 1e9

int graph[200][200], visited[200], result[200];
bool iter[200];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, a, b, c;
	priority_queue<tuple<int, int, int>> pq;
	// 가중치 값, 방문 정점 값, 초기 값
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		fill(graph[i], graph[i] + 200, INF);
		graph[i][i] = 0;
	}
	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c);
		graph[b - 1][a - 1] = min(graph[b - 1][a - 1], c);
	}
	for (i = 0; i < N; i++) {
		fill(visited, visited + 200, INF);
		fill(result, result + 200, -1);
		fill(iter, iter + 200, 0);
		visited[i] = 0;
		for (j = 0; j < N; j++) {
			if (i == j) continue;
			if (graph[i][j] != INF) {
				pq.push({graph[i][j], j, j});
				// cout << j << " ";
			}
		}
		while (pq.size()) {
			tie(a, b, c) = pq.top();
			// 가중치 값, 방문 정점 값, 초기 값
			pq.pop();
			if (a < visited[b]) {
				iter[b] = 1;
				visited[b] = a;
				result[b] = c;
				for (j = 0; j < N; j++) {
					if (b == j) continue;
					if (graph[b][j] != INF && a + graph[b][j] < visited[j]) {
						pq.push({a + graph[b][j], j, c});
					}
				}
			}
		}
		for (j = 0; j < N; j++) {
			if (result[j] == -1) {
				cout << "- ";
			} else {
				cout << result[j] + 1 << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}