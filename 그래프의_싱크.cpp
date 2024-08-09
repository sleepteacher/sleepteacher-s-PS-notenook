#include <bits/stdc++.h>

using namespace std;

int dr, dr_rank[5001], tag[5001], isres[5001];
vector<vector<int>> SCC(1), graph(5001);
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
		SCC.push_back(memo);
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int TC, N, M, i, j, k, l, a, b, iter = 0, result = 0, start, start_SCC;
	while (1) {
		dr = 0;
		fill(dr_rank, dr_rank + 5001, 0);
		fill(tag, tag + 5001, 0);
		fill(isres, isres + 5001, 0);
		graph = vector<vector<int>>(5001);
		cin >> N;
		if (!N) break;
		cin >> M;
		for (i = 0; i < M; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
		}
		for (i = 1; i <= N; i++) {
			if (!tag[i]) {
				DFS(i);
			}
		}
		for (i = 1; i <= N; i++) {
			if (isres[i]) continue;
			int con = 1;
			for (j = 0; j < SCC[tag[i]].size(); j++) {
				int node = SCC[tag[i]][j];
				for (k = 0; k < graph[node].size(); k++) {
					if (tag[i] != tag[graph[node][k]]) {
						con = 0, j = 50000;
						break;
					}
				}
			}
			if (con) {
				for (j = 0; j < SCC[tag[i]].size(); j++) {
					int node = SCC[tag[i]][j];
					isres[node] = 1;
				}
			} else {
				for (j = 0; j < SCC[tag[i]].size(); j++) {
					int node = SCC[tag[i]][j];
					isres[node] = -1;
				}
			}
		}
		for (i = 1; i <= N; i++) {
			if (isres[i] == 1) cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}