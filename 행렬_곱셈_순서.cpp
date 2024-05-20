#include <bits/stdc++.h>

using namespace std;
pair<int, int> ip[500], change;
unsigned int dp[500][500];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, i, j, k, l, a, b;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		ip[i] = {a, b};
	}
	for (i = 0; i < N; i++) {
		fill(dp[i], dp[i] + 502, INT_MAX);
		dp[i][i] = 0;
	}
	for (i = 1; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; j + k < j + i; k++) {
				if (j + i < N) {
					dp[j][j + i] = min(dp[j][j + k] + dp[j + k + 1][j + i] + ip[j].first * ip[j + k + 1].first * ip[j + i].second, dp[j][j + i]);
				}
			}
		}
	}
	cout << dp[0][N - 1] << "\n";

	return 0;
}