#include <bits/stdc++.h>

using namespace std;

int dp[200004];

/*
1 2 3 4
2 3 4 5

*/
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, iter, start;
	long long S = 0;
	cin >> N >> M;
	fill(dp, dp + 200004, 1);
	for (i = 0; i < N; i++) {
		cin >> l;
		for (j = 0; j < 4; j++) dp[(i + j) % N] *= l;
	}
	for (i = 0; i < N; i++) S += dp[i];
	for (l = 0; l < M; l++) {
		cin >> i;
		i--;
		for (j = 0; j < 4; j++) {
			dp[(i + j) % N] *= -1;
			S += dp[(i + j) % N] * 2;
		}
		cout << S << "\n";
	}

	return 0;
}