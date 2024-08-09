#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

int N, M, graph[101][101], dp[3][101][101], dx[3][4] = {{-1, 1, 0, 0}, {1, -1, -999, -999}, {0, 0, -999, -999}}, dy[3][4] = {{0, 0, 1, -1}, {0, 0, -999, -999}, {1, -1, -999, -999}};
// value, x,y, cnt;
priority_queue<tuple<int, int, int, int>> pq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, a, b, c, d, val, x, y, cnt, result;
	cin >> N >> M >> a >> b >> c >> d;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 101; j++) fill(dp[i][j], dp[i][j] + 101, INF);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			cin >> graph[i][j];
		}
	}
	pq.push({a, b, 1, 0});
	while (pq.size()) {
		tie(x, y, cnt, val) = pq.top();
		// cout << val << " " << x << " " << y << " " << cnt << "\n";
		pq.pop();
		if (val >= dp[cnt][x][y] || val >= min({dp[0][c][d], dp[1][c][d], dp[2][c][d]})) continue;
		dp[cnt][x][y] = val;
		if (x == c && y == d) continue;
		for (i = 0; i < 4; i++) {
			int nx = x + dx[cnt][i], ny = y + dy[cnt][i];
			if (nx <= 0 || ny <= 0 || nx >= N + 1 || ny >= M + 1 || graph[nx][ny] == -1) continue;
			if (val + graph[nx][ny] < dp[(cnt + 1) % 3][nx][ny]) pq.push({nx, ny, (cnt + 1) % 3, val + graph[nx][ny]});
		}
	}
	result = min({dp[0][c][d], dp[1][c][d], dp[2][c][d]});
	if (result == INF) {
		cout << -1 << "\n";
	} else {
		cout << result << "\n";
	}
	return 0;
}