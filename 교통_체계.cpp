#include <bits/stdc++.h>

using namespace std;

bool isdis[100001];
int visited_rank[100001], dfs_rank;
vector<int> graph[100001];
vector<pair<int, int>> result;

int DFS(bool root, int now, int par) {
	int i, j, k, l, dr = ++dfs_rank, son = 0;
	visited_rank[now] = dr;
	for (i = 0; i < graph[now].size(); i++) {
		int child = graph[now][i];
		if (!visited_rank[child]) {
			son++;
			dr = min(dr, DFS(0, child, now));
			if (dr >= visited_rank[now] && !root) {
				isdis[i] = 1;
			}
		} else {
			dr = min(dr, visited_rank[child]);
		}
	}
	if (root && son > 1) {
		isdis[now] = 1;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, E, Q, a, b, c, d, input;

	cin >> N >> E;
	for (i = 0; i < E; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1, 1, 0);
	cin >> Q;
	for (i = 0; i < Q; i++) {
		cin >> input;
		if (input == 1) {
			cin >> a >> b >> c >> d;

		} else {
			cin >> a >> b >> c;
		}
	}
	/*
	1 - a, b, g1 ,g2
	2 - a, b, c
	*/

	return 0;
}