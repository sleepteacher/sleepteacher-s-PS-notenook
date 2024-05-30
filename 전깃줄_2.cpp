#include <bits/stdc++.h>

using namespace std;

int origin[500001];
main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, idx, val, iter_start = 9999999, iter_max = 0, stack = 0;
	vector<int> result, dp, re;

	fill(origin, origin + 500001, -1);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> idx >> val;
		origin[idx] = val;
		iter_max = max(iter_max, idx);
		iter_start = min(iter_start, idx);
	}
	dp.push_back(origin[iter_start]);
	for (i = iter_start + 1; i < iter_max; i++) {
		if (origin[i] == -1) {
			continue;
		}
		int loca = upper_bound(dp.begin(), dp.end(), origin[i]) - dp.begin();
		if (loca == dp.size()) {
			dp.push_back(origin[i]);
		} else {
			dp[loca] = origin[i];
		}
	}
	/*
	re = vector<int>(dp.size());
	for (i = iter_start; i < iter_max; i++) {
		if (origin[i] == -1) {
			continue;
		}
		int loca = lower_bound(dp.begin(), dp.end(), origin[i]) - dp.begin();
		if (loca < dp.size()) {
			if (origin[i] != dp[loca]) {
				result.push_back(i);
			}
		} else {
			result.push_back(i);
		}
	}

	cout << result.size() << "\n";
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	*/

	return 0;
}
