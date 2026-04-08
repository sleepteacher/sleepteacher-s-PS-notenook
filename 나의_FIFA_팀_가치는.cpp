#include <bits/stdc++.h>

using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, K, result = 0;
	priority_queue<int> V[11];
	cin >> N >> K;
	for (i = 0; i < N; i++) {
		cin >> j >> k;
		V[--j].push(k);
	}
	for (i = 0; i < 11; i++) {
		if (!V[i].size()) continue;
		k = V[i].top();
		V[i].pop();
		for (j = 0; j < K && k; j++) {
			V[i].push(--k);
			k = V[i].top();
			V[i].pop();
		}
		result += k;
	}
	cout << result << "\n";

	return 0;
}
