#include <bits/stdc++.h>

using namespace std;

int dp[1001];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N;
	cin >> N;
	fill(dp, dp + 1001, 1e9);
	dp[1] = 0;
	for (i = 1; i <= N; i++) {
		cin >> j;
		if (1e9 == dp[i]) continue;
		for (; j > 0; j--) {
			dp[min(i + j, N)] = min(dp[min(i + j, N)], dp[i] + 1);
		}
	}
	if (dp[N] == 1e9) {
		cout << -1;
	} else {
		cout << dp[N];
	}

	return 0;
}