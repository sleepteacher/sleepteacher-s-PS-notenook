#include <bits/stdc++.h>

using namespace std;

int origin[1000001];
main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, idx, val, iter_start = 9999999, iter_max = 0, stack = 0;
	vector<int> result, dp, re;

	fill(origin, origin + 1000001, -1);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> origin[i];
	}
	for (i = 0; i < N; i++) {
		if (origin[i] == -1) {
			continue;
		}
		int loca = lower_bound(dp.begin(), dp.end(), origin[i]) - dp.begin();
		if (loca == dp.size()) {
			dp.push_back(origin[i]);
		} else {
			dp[loca] = origin[i];
		}
	}
	cout << dp.size() << "\n";
	for (i = 0; i < dp.size(); i++) {
		cout << dp[i] << " ";
	}

	return 0;
}
