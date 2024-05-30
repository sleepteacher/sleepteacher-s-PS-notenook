#include <bits/stdc++.h>

using namespace std;

int forigin[100001], sorigin[100001], freget[100001], sreget[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N;
	vector<int> result, dp, re;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> forigin[i];
	}
	for (i = 0; i < N; i++) {
		cin >> sorigin[i];
	}
	for (i = 0; i < N; i++) {
		int loca = lower_bound(dp.begin(), dp.end(), forigin[i]) - dp.begin();
		if (loca == dp.size()) {
			dp.push_back(forigin[i]);
		} else {
			dp[loca] = forigin[i];
		}
		freget[i
		
		] = loca;
	}
	dp = vector<int>(0);
	for (i = 0; i < N; i++) {
		sorigin[i] = sreget[sorigin[i]];
		int loca = lower_bound(dp.begin(), dp.end(), sorigin[i]) - dp.begin();
		if (loca == dp.size()) {
			dp.push_back(sorigin[i]);
		} else {
			dp[loca] = sorigin[i];
		}
	}
	cout << dp.size() << "\n";

	return 0;
}
