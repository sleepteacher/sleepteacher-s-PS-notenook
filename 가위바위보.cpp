#include <bits/stdc++.h>

using namespace std;

int val[51], visited[51], BK = 9999;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, K, M, iter, iter_k, con;
	string in;
	vector<pair<string, int>> V, cmp;
	queue<pair<int, vector<pair<string, int>>>> pq;
	// iter, vector
	fill(val, val + 51, INT_MAX / 2);
	fill(visited, visited + 51, 0);
	cin >> N >> M >> K;
	for (i = 0; i < N; i++) {
		cin >> in;
		con = 1;
		for (j = 0; j < V.size(); j++) {
			if (in == V[i].first) {
				V[i].second++;
				con = 0;
			}
		}
		if (con) {
			V.push_back({in, 1});
		}
	}
	sort(V.begin(), V.end());
	pq.push({0, V});
	while (pq.size()) {
		tie(iter, V) = pq.front();
		pq.pop();
		if (BK <= iter) {
			continue;
		}
		if (!visited[iter_k] && iter < val[iter_k]) {
		}
	}

	return 0;
}