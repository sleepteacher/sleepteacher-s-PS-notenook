#include <bits/stdc++.h>

using namespace std;

int dp[100010];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N;
	cin >> N;
	fill(dp, dp + 100001, 123123213);
	dp[N] = 0;
	for (i = N; i > 0; i--) {
		if (i - 1 >= 0)
			dp[i - 1] = min(dp[i] + 1, dp[i - 1]);
		if (i - 2 >= 0)
			dp[i - 2] = min(dp[i] + 1, dp[i - 2]);
		if (i - 5 >= 0)
			dp[i - 5] = min(dp[i] + 1, dp[i - 5]);
		if (i - 7 >= 0)
			dp[i - 7] = min(dp[i] + 1, dp[i - 7]);
	}
	cout << dp[0] << "\n";

	return 0;
}