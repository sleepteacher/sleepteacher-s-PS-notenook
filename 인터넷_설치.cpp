#include <bits/stdc++.h>

#define ll long long
using namespace std;

int val[1001][1001], N, P, K;
vector<pair<int, int>> graph[1001];

queue<tuple<int, int, int>> PQ;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, a, b, c, result = 1e9;
	cin >> N >> P >> K;
	for (i = 0; i <= N; i++) {
		fill(val[i], val[i] + 1001, 1e9);
	}
	for (i = 0; i < P; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	PQ.push({1, K, 0});
	while (PQ.size()) {
		int node = get<0>(PQ.front()), Z = get<1>(PQ.front()), now = get<2>(PQ.front());
		PQ.pop();
		if (val[node][Z] <= now) continue;
		val[node][Z] = now;
		if (node == N) continue;
		for (i = 0; i < graph[node].size(); i++) {
			if (now < graph[node][i].second) {
				if (graph[node][i].second < val[i][Z]) PQ.push({i, Z, graph[node][i].second});
				if (Z && now < val[i][Z - 1]) {
					PQ.push({i, Z - 1, now});
				}
			} else {
				if (now < val[i][Z]) PQ.push({i, Z, now});
			}
		}
	}
	for (i = 0; i <= K; i++) {
		result = min(val[N][i], result);
	}
	if (result == 1e9) {
		cout << -1 << "\n";
	} else {
		cout << result << "\n";
	}
	return 0;
}