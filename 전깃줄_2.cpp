#include <bits/stdc++.h>

using namespace std;

int forigin[100001], sorigin[100001], seget[500001];
main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, idx, val, iter_start = 9999999, iter_end = 0, stack = 0;
	vector<int> result, dp;

	fill(origin, origin + 500001, -1);
	fill(reget, reget + 500001, -1);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> idx >> val;
		origin[idx] = val;
		iter_end = max(iter_end, idx);
		iter_start = min(iter_start, idx);
	}
	dp.push_back(origin[iter_start]);
	reget[iter_start] = 0;
	for (i = iter_start + 1; i <= iter_end; i++) {
		if (origin[i] == -1) {
			continue;
		}
		int loca = lower_bound(dp.begin(), dp.end(), origin[i]) - dp.begin();
		if (loca == dp.size()) {
			dp.push_back(origin[i]);
		} else {
			dp[loca] = origin[i];
		}
		reget[i] = loca;
	}
	stack = dp.size() - 1;

	for (i = iter_end; i >= iter_start; i--) {
		if (origin[i] == -1) {
			continue;
		}
		if (reget[i] == stack) {
			stack--;
		} else {
			result.push_back(i);
		}
	}

	cout << result.size() << "\n";
	for (i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << "\n";
	}

	return 0;
}
