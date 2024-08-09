#include <bits/stdc++.h>

using namespace std;

int dr, dr_rank[10001], tag[10001], val[10001], SCC_dp[10001];
// 순회 순서, 순회 순서 배열, SCC의 배열 내 값, 선입력된 노드가 위상적으로 어떤 타일 번호를 가지는지 알려줌
// 원 노드의 값
vector<int> graph[10001];
stack<int> S;
vector<vector<int>> SCC(1), SCC_CON(10001);
bool visited[10001];

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
	int TC, N, M, i, j, k, l, a, b, iter = 0, result = 0, start, end, start_SCC, end_SCC;
	priority_queue<pair<int, int>> Q;
	cin >> N >> M >> start >> end;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (i = 1; i <= N; i++) {
		if (!tag[i]) {
			DFS(i);
		}
	}

	start_SCC = tag[start], end_SCC = tag[end];
	if (start_SCC == end_SCC) {
		result = SCC[start_SCC].size();
	} else {
		for (i = 1; i < SCC.size(); i++) {
			if (!val[i]) val[i] = SCC[i].size();
			fill(visited, visited + 10001, 0);
			visited[i] = 1;
			for (j = 0; j < SCC[i].size(); j++) {
				int node = SCC[i][j];
				for (k = 0; k < graph[node].size(); k++) {
					if (!visited[tag[graph[node][k]]]) {
						visited[tag[graph[node][k]]] = 1;
						SCC_CON[i].push_back(tag[graph[node][k]]);
					}
				}
			}
		}

		for (i = 0; i < SCC_CON[start_SCC].size(); i++) {
			Q.push({SCC_CON[start_SCC][i], val[start_SCC]});
		}
		while (Q.size()) {
			int node = Q.top().first, sum = Q.top().second;
			Q.pop();
			if (sum < SCC_dp[node]) continue;
			SCC_dp[node] = sum;
			if (node == end_SCC) result = max(val[node] + sum, result);
			for (i = 0; i < SCC_CON[node].size(); i++) {
				Q.push({SCC_CON[node][i], sum + val[node]});
			}
		}
	}

	cout << result << "\n";

	return 0;
}