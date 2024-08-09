#include <bits/stdc++.h>

using namespace std;

int dr, dr_rank[500001], tag[500001], val[500001], SCC_dp[500001];
// 순회 순서, 순회 순서 배열, SCC의 배열 내 값, 선입력된 노드가 위상적으로 어떤 타일 번호를 가지는지 알려줌
// 원 노드의 값
vector<int> graph[500001];
stack<int> S;
vector<vector<int>> SCC(1);
unordered_set<int> SCC_CON[500001];
bool isres[500001];

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
	priority_queue<pair<int, int>> Q;
	cin >> N >> M;
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
		cin >> a;
		val[tag[i]] += a;
	}
	cin >> start >> b;
	for (i = 0; i < b; i++) {
		cin >> a;
		isres[tag[a]] = 1;
	}
	for (i = 1; i <= N; i++) {
		for (j = 0; j < graph[i].size(); j++) {
			if (tag[i] != tag[graph[i][j]]) {
				SCC_CON[tag[i]].insert(tag[graph[i][j]]);
			}
		}
	}
	start_SCC = tag[start];
	if (isres[start_SCC]) result = val[tag[start]];

	for (auto iter = SCC_CON[start_SCC].begin(); iter != SCC_CON[start_SCC].end(); iter++) {
		Q.push({*iter, val[start_SCC]});
	}
	while (Q.size()) {
		int node = Q.top().first, sum = Q.top().second;
		Q.pop();

		if (sum < SCC_dp[node]) continue;
		SCC_dp[node] = sum;
		if (isres[node]) result = max(val[node] + sum, result);
		for (auto iter = SCC_CON[node].begin(); iter != SCC_CON[node].end(); iter++) {
			Q.push({*iter, sum + val[node]});
		}
	}
	cout << result << "\n";

	return 0;
}