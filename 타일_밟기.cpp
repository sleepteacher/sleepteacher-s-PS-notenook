#include <bits/stdc++.h>

using namespace std;

int ishave[2000001], arr[3001];
bool searched[1000001];
vector<pair<int, long long>> dp[3001];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N;
	long long result = 0;
	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
		ishave[arr[i]] = i;
	}
	for (i = 2; i <= N; i++) {
		fill(searched, searched + 1000001, 0);
		for (j = 0; j < dp[i].size(); j++) {
			int diff = dp[i][j].first;
			result = max(result, dp[i][j].second + arr[i]);
			if (ishave[arr[i] + diff]) {
				searched[diff] = 1;
				dp[ishave[arr[i] + diff]].push_back({diff, dp[i][j].second + arr[i]});
			}
		}
		for (j = i - 1; j != 0; j--) {
			int Cnum = arr[i] - arr[j];
			if (searched[Cnum]) continue;
			if (arr[N] < arr[i] + Cnum) break;
			int next = ishave[arr[i] + Cnum];
			if (next) {
				dp[next].push_back({Cnum, arr[i] * 2 - Cnum});
			}
		}
	}
	cout << result << "\n";

	return 0;
}