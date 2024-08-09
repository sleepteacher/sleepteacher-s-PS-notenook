#include <bits/stdc++.h>

using namespace std;

int dr, dr_rank[100001], tag[100001], indeg[100001];
vector<vector<int>> SCC(1), graph(100001);
stack<int> S;

int DFS(int snode) {
	int i, j, k, l, child, ret = ++dr, ST, result = 0;
	vector<int> memo;
	dr_rank[snode] = dr;
	S.push(snode);
	for (i = 0; i < graph[snode].size(); i++) {
		child = graph[snode][i];
		if (tag[child]) continue;
		if (dr_rank[child]) {
			ret = min(ret, dr_rank[child]);
		} else {
			ret = min(ret, DFS(child));
		}
	}
	if (ret == dr_rank[snode]) {
		while (1) {
			ST = S.top();
			S.pop();
			tag[ST] = SCC.size();
			memo.push_back(ST);
			if (ST == snode)
				break;
		}
		sort(memo.begin(), memo.end());
		SCC.push_back(memo);
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int TC, N, M, i, j, k, l, a, b, iter = 0, result = 0, start, start_SCC;
	cin >> TC;
	while (TC--) {
		dr = 0;
		fill(dr_rank, dr_rank + 100001, 0);
		fill(tag, tag + 100001, 0);
		fill(indeg, indeg + 100001, 0);
		graph = vector<vector<int>>(100001);
		SCC = vector<vector<int>>(1);
		cin >> N;
		if (!N) break;
		cin >> M;
		for (i = 0; i < M; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
		}
		for (i = 0; i < N; i++) {
			if (!tag[i]) {
				DFS(i);
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < graph[i].size(); j++) {
				if (tag[i] != tag[graph[i][j]]) {
					indeg[tag[graph[i][j]]]++;
				}
			}
		}
		result = 0;
		for (i = 1; i < SCC.size(); i++) {
			if (indeg[i] == 0) result++, start_SCC = i;
		}
		if (result == 1) {
			for (i = 0; i < SCC[start_SCC].size(); i++) {
				cout << SCC[start_SCC][i] << "\n";
			}
		} else {
			cout << "Confused" << "\n";
		}

		cout << "\n";
	}

	return 0;
}