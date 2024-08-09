#include <bits/stdc++.h>

using namespace std;

long long dp[50][100];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, R, C, W;
	long long result = 0;
	dp[1][1] = 1;
	for (i = 2; i < 49; i++) {
		for (j = 1; j <= i; j++) {
			if (j == i || j == 1) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			}
		}
	}
	cin >> R >> C >> W;
	for (i = R; i < R + W; i++) {
		for (j = C; j <= C + i - R; j++) {
			result += dp[i][j];
		}
	}
	cout << result << "\n";
	return 0;
}