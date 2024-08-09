#include <bits/stdc++.h>

using namespace std;

int dr, dr_rank[100001], tag[100001], ind[100001];
vector<int> graph[100001];
stack<int> S;
bool fin[100001];
vector<vector<int>> SCC;

int DFS(int snode) {
	int i, j, k, l, child, ret = ++dr, ST;
	vector<int> memo;
	dr_rank[snode] = dr;
	S.push(snode);
	for (i = 0; i < graph[snode].size(); i++) {
		child = graph[snode][i];
		if (fin[child]) continue;
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
			fin[ST] = 1;
			tag[ST] = SCC.size() + 1;
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
	int TC, N, M, i, j, k, l, a, b, iter = 0, result;
	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		dr = 0, result = 0;
		fill(fin, fin + N + 1, 0);
		fill(dr_rank, dr_rank + N + 1, 0);
		fill(ind, ind + N + 1, 0);
		fill(tag, tag + N + 1, 0);
		SCC = vector<vector<int>>();
		for (i = 1; i <= N; i++) {
			graph[i] = vector<int>();
		}
		dr = 0;
		for (i = 0; i < M; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
		}
		for (i = 1; i <= N; i++) {
			if (!fin[i]) {
				DFS(i);
			}
		}

		for (i = 0; i < SCC.size(); i++) {
			for (j = 0; j < SCC[i].size(); j++) {
				int node = SCC[i][j];
				for (k = 0; k < graph[node].size(); k++) {
					if (tag[node] != tag[graph[node][k]]) {
						ind[tag[graph[node][k]]]++;
					}
				}
			}
		}
		for (i = 1; i <= SCC.size(); i++) {
			result += ind[i] == 0;
		}
		cout << result << "\n";
	}

	return 0;
}