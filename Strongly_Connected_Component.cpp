#include <bits/stdc++.h>

using namespace std;

int search_size;
vector<int> graph[10001];
vector<pair<int, int>> dtree[10001];
bool visited[10001], finish[10001];

int DFS(int snode) {
	int i, j, k, l;
	for (i = 0; i < graph[snode].size(); i++) {
		if (!visited[graph[snode][i]]) {
			visited[graph[snode][i]]++;
			dtree[snode].push_back({graph[snode][i], ++search_size});
			DFS(graph[snode][i]);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, i, j, k, l, a, b;
	cin >> N >> M;
	graph[0].push_back(1);
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1);

	return 0;
}