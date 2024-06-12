#include <bits/stdc++.h>

using namespace std;

int N, M, dp[101][10001];
pair<int, int> arr[100];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> arr[i].first;
	}
	for (i = 0; i < N; i++) {
		cin >> arr[i].second;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j <= 10000; j++) {
			dp[i + 1][j] = dp[i][j];
		}
		for (j = 0; j <= 10000 - arr[i].second; j++) {
			dp[i + 1][j + arr[i].second] = max({dp[i][j] + arr[i].first, dp[i][j + arr[i].second]});
		}
	}
	for (i = 0; i <= 10000; i++) {
		if (dp[N][i] >= M) {
			cout << i;
			break;
		}
	}

	return 0;
}