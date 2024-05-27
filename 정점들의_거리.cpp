#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> info[100001];
pair<int, long long> dp[100001][17];
queue<int> Q;
int depth[100001];
bool visited[100001];

long long LCA(int a, int b, int c, int mode) {
	int i, j, k, l, dif, iter, u = a, v = b;
	long long iter_a = 0, iter_b = 0;
	if (depth[a] < depth[b]) {
		i = a;
		a = b;
		b = i;
	}
	dif = depth[a] - depth[b], iter;
	for (i = 0; i < 17; i++) {
		iter = 1 << i;
		if ((dif | iter) == dif) {
			iter_a += dp[a][i].second;
			a = dp[a][i].first;
		}
	}
	if (a != b) {
		for (i = 16; i >= 0; i--) {
			if ((dp[a][i].first != 0) && (dp[a][i].first != dp[b][i].first)) {
				iter_a += dp[a][i].second;
				iter_b += dp[b][i].second;
				a = dp[a][i].first;
				b = dp[b][i].first;
			}
		}
		iter_a += dp[a][0].second;
		iter_b += dp[b][0].second;
		a = dp[a][0].first;
	}
	if (mode - 1) {
		if (c < depth[u] - depth[a] + 1) {
			dif = c - 1;
			for (i = 0; i < 17; i++) {
				iter = 1 << i;
				if ((dif | iter) == dif) {
					u = dp[u][i].first;
				}
			}
			return u;
		} else if (c == depth[u] - depth[a] + 1) {
			return a;
		} else {
			dif = -(c - (depth[u] - depth[a] + 1)) + depth[v] - depth[a];
			for (i = 0; i < 17; i++) {
				iter = 1 << i;
				if ((dif | iter) == dif) {
					v = dp[v][i].first;
				}
			}
			return v;
		}
	} else {
		return iter_a + iter_b;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int i, j, k, l, T, N, a, b, c, mode;

	fill(visited, visited + 100001, 1);
	cin >> N;
	cin >> a >> b >> c;
	dp[a][0].first = 0, depth[a] = 1, visited[0] = 0;
	info[a].push_back({b, c});
	info[b].push_back({a, c});
	Q.push(a);
	for (i = 0; i < N - 2; i++) {
		cin >> a >> b >> c;
		info[a].push_back({b, c});
		info[b].push_back({a, c});
	}
	while (!Q.empty()) {
		int vertex = Q.front();
		Q.pop();
		visited[vertex] = 0;
		for (i = 0; i < info[vertex].size(); i++) {
			int now = info[vertex][i].first, val = info[vertex][i].second;
			if (visited[now]) {
				depth[now] = depth[vertex] + 1;
				dp[now][0].first = vertex;
				dp[now][0].second = val;
				for (j = 0; j < 16; j++) {
					if (dp[dp[now][j].first][j].first != 0) {
						dp[now][j + 1].first = dp[dp[now][j].first][j].first;
						dp[now][j + 1].second =
							dp[dp[now][j].first][j].second + dp[now][j].second;
					}
				}
				Q.push(now);
			}
		}
	}
	cin >> T;
	mode = 1;
	for (i = 0; i < T; i++) {
		// cin >> mode;
		if (mode - 1) {
			cin >> a >> b >> c;
			cout << LCA(a, b, c, mode) << "\n";
			// LCA(a, b, c, mode);
		} else {
			cin >> a >> b;
			cout << LCA(a, b, 0, mode) << "\n";
		}
	}

	return 0;
}