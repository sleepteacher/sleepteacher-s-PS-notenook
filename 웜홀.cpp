#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M, W, TC, i, j, k, l, a, b, c, con;
	cin >> TC;
	for (i = 0; i < TC; i++) {
		con = 1;
		vector<vector<int>> dp_graph(501, vector<int>(501, 1e9));
		cin >> N >> M >> W;
		for (j = 0; j < M; j++) {
			cin >> a >> b >> c;
			dp_graph[a][b] = min(dp_graph[a][b], c);
			dp_graph[b][a] = min(dp_graph[b][a], c);
		}
		for (j = 0; j < W; j++) {
			cin >> a >> b >> c;
			dp_graph[a][b] = min(dp_graph[a][b], -c);
		}
		for (j = 1; j <= N; j++) {
			for (k = 1; k <= N; k++) {
				for (l = 1; l <= N; l++) {
					dp_graph[j][k] = min(dp_graph[j][l] + dp_graph[l][k], dp_graph[j][k]);
				}
			}
		}
		for (j = 1; j <= N; j++) {
			if (dp_graph[j][j] < 0) {
				con = 0;
			}
		}
		if (con) {
			cout << "NO" << "\n";
		} else {
			cout << "YES" << "\n";
		}
	}

	return 0;
}