#include <bits/stdc++.h>

using namespace std;
long long dp[31][31], N;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l;
	cin >> N;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> dp[i][j];
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			dp[i][j] += max((dp[i - 1][j] << 1), (dp[i][j - 1] << 1));
		}
	}
	cout << dp[N][N] << "\n";

	return 0;
}