#include <bits/stdc++.h>

using namespace std;

int dr, dr_rank[10001];
vector<int> graph[10001];
stack<int> S;
bool fin[10001];
vector<vector<int>> SCC;

int DFS(int snode) {
	int i, j, k, l, child, ret = ++dr, ST;
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
		vector<int> memo;
		while (1) {
			ST = S.top();
			S.pop();
			fin[ST] = 1;
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
	int N, M, i, j, k, l, a, b;
	cin >> N >> M;
	graph[0].push_back(1);
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (i = 1; i <= N; i++) {
		if (!fin[i]) DFS(i);
	}
	cout << SCC.size() << "\n";
	sort(SCC.begin(), SCC.end());
	for (i = 0; i < SCC.size(); i++) {
		for (j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << " ";
		}
		cout << -1 << "\n";
	}
	return 0;
}