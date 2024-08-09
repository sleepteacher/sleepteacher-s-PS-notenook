#include <bits/stdc++.h>

using namespace std;

int ds, depth[100001];
vector<int> graph[100001];
vector<pair<int, int>> result;

int DFS(int snode, int parent) {
	int i, j, k, l, son = 0, ret = ++ds, df;
	depth[snode] = ds;
	for (i = 0; i < graph[snode].size(); i++) {
		if (graph[snode][i] == parent)
			continue;
		if (!depth[graph[snode][i]]) {
			df = DFS(graph[snode][i], snode);
			if ((df > depth[snode])) {
				result.push_back({min(graph[snode][i], snode), max(graph[snode][i], snode)});
			}
			ret = min(df, ret);
		} else {
			ret = min(depth[graph[snode][i]], ret);
		}
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, i, j, k, l, a, b;
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
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (i = 0; i < result.size(); i++) {
		cout << result[i].first << " " << result[i].second << "\n";
	}

	return 0;
}