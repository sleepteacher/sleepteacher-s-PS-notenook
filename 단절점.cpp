#include <bits/stdc++.h>

using namespace std;

int ds, depth[10001];
vector<int> graph[10001];
bool cut[10001];

int DFS(int snode, bool root) {
	int i, j, k, l, son = 0, ret = ++ds, df;
	depth[snode] = ds;
	for (i = 0; i < graph[snode].size(); i++) {
		if (!depth[graph[snode][i]]) {
			son++;
			df = DFS(graph[snode][i], 0);
			if ((df >= depth[snode]) && !root) {
				cut[snode] = 1;
			}
			ret = min(df, ret);
		} else {
			ret = min(depth[graph[snode][i]], ret);
		}
	}
	if (root && son > 1) {
		cut[snode] = 1;
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, i, j, k, l, a, b, result = 0;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (i = 1; i <= N; i++) {
		if (!depth[i]) {
			DFS(i, 1);
		}
	}
	for (i = 1; i <= N; i++) {
		result += cut[i];
	}
	cout << result << "\n";
	for (i = 1; i <= N; i++) {
		if (cut[i]) {
			cout << i << " ";
		}
	}

	return 0;
}