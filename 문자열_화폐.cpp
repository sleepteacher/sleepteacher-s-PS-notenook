#include <bits/stdc++.h>

using namespace std;

int dp[27];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, K;

	cin >> N >> K;
	if (N <= K && K <= N * 26) {
		dp[26] = K / 26;
		N -= dp[26];
		K %= 26;
		while (1) {
			if (N <= K) {
				dp[1] = N - 1;
				K -= N - 1;
				dp[K]++;
				break;
			} else {
				k = (N + 25 - K) / 26;
				N += k;
				dp[26] -= k;
				K += 26 * k;
			}
		}
		for (i = 1; i < 27; i++) {
			while (dp[i]--) {
				cout << (char)('A' + i - 1);
			}
		}
	} else {
		cout << "!";
	}
	return 0;
}