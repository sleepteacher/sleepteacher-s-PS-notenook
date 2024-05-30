#include <bits/stdc++.h>

using namespace std;

int forigin[100001], sidx[100001], dp[100001], reget[100001], idx_table[100001], result[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, idx, input, op = 0;
	vector<int> dp;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> forigin[i];
		idx_table[forigin[i]] = i;
	}
	for (i = 0; i < N; i++) {
		cin >> input;
		sidx[i] = idx_table[input];
	}
	for (i = 0; i < N; i++) {
		int loca = lower_bound(dp.begin(), dp.end(), sidx[i]) - dp.begin();
		if (loca == dp.size()) {
			dp.push_back(sidx[i]);
		} else {
			dp[loca] = sidx[i];
		}
		reget[i] = loca;
	}
	cout << dp.size() << "\n";

	return 0;
}
