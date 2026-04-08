#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, TC, N, K, a, b;
	pair<long long, long long> S[3];
	cin >> TC;
	while (TC--) {
		vector<pair<int, int>> V;
		S[1] = S[2] = {0, 0};
		cin >> N >> K;
		for (i = 0; i < N; i++) {
			cin >> a;
			V.push_back({a, 1});
		}
		for (i = 0; i < N; i++) {
			cin >> V[i].second;
		}
	}

	return 0;
}