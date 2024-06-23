#include <bits/stdc++.h>

using namespace std;
int dp[501][500];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, T, N, con, S;

	cin >> T;
	while (T--) {
		int val, min_val;
		S = 0;
		long long result = 0;
		cin >> N;
		for (i = 0; i < N; i++) {
			fill(dp[i + 1], dp[i + 1] + 500, 999);
			cin >> dp[0][i];
		}
		for (i = 1; i < N; i++) {
			val = dp[i - 1][0] + dp[i - 1][1], min_val = min(dp[i - 1][0], dp[i - 1][1]), con = 0, S = 0;
			for (j = 0; j < N - i; j++) {
				if (min(dp[i - 1][j], dp[i - 1][j + 1]) <= min_val) {
					if (dp[i - 1][j] != dp[i - 1][j + 1] && val >= dp[i - 1][j] + dp[i - 1][j + 1]) {
						con = j, val = dp[i - 1][j] + dp[i - 1][j + 1], min_val = min(dp[i - 1][j], dp[i - 1][j + 1]);
					}
				}
			}
			result += val;
			for (j = 0; j < N - i; j++) {
				if (j == con) {
					dp[i][j] = val;
					S = 1;
				} else {
					dp[i][j] = dp[i - 1][j + S];
				}
			}
		}
		cout << result << "\n";
	}

	return 0;
}