#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, T, N, K, X, Y, W, D, a, b, idx;
	cin >> T;
	while (T--) {
		vector<int> value(1001, 0), sum(1001, 0), use(1001, 0), graph[1001], out_graph[1001];
		queue<int> Q;
		stack<int> S;
		int result = 0;
		bool visited[1001];
		fill(visited, visited + 1001, 0);
		cin >> N >> K;
		for (i = 1; i <= N; i++) cin >> value[i];
		while (K--) {
			cin >> a >> b;
			graph[b].push_back(a);
			out_graph[a].push_back(b);
			sum[b]++;
		}
		cin >> result;
		idx = result;
		S.push(idx);
		// 입력
		while (S.size()) {
			idx = S.top();
			S.pop();
			if (visited[idx] == 0) {
				visited[idx] = 1;
				for (i = 0; i < graph[idx].size(); i++) {
					S.push(graph[idx][i]);
				}
			}
		}
		// 방문 사이클 확인
		for (i = 1; i <= N; i++)
			if (visited[i] && !sum[i]) S.push(i);
		// 위상 정렬 준비
		while (S.size()) {
			idx = S.top();
			S.pop();
			use[idx] = value[idx];
			for (i = 0; i < graph[idx].size(); i++) {
				use[idx] = max(use[graph[idx][i]] + value[idx], use[idx]);
			}
			for (i = 0; i < out_graph[idx].size(); i++) {
				sum[out_graph[idx][i]]--;
				if (sum[out_graph[idx][i]] == 0 && visited[out_graph[idx][i]]) {
					S.push(out_graph[idx][i]);
				}
			}
		}

		cout << use[result] << "\n";
	}

	return 0;
}