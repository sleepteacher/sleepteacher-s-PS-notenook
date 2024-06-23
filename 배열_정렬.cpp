#include <bits/stdc++.h>

using namespace std;
tuple<int, int, int> CT[12];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k = 0, l, a, b, w, con, N, M, result_key = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
		Q;
	vector<int> pa;
	map<int, int> val_set;

	cin >> N;
	vector<int> arr(N + 1, 0), sorted(N + 1, 0);
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
		sorted[i] = arr[i];
	}
	sort(sorted.begin(), sorted.end());
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> a >> b >> w;
		CT[i] = {a, b, w};
	}
	k = 0, l = 1;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (arr[i] == sorted[j]) {
				if (k < l) {
					k += j * l;
					pa.push_back(j);
				}
			}
		}
		l *= 10;
	}
	sort(pa.begin(), pa.end());
	result_key = 0, l = 1;
	for (i = 0; i < N; i++) {
		result_key += pa[i] * l;
		l *= 10;
	}
	val_set[result_key] = INT_MAX;
	Q.push({0, k});
	while (Q.size()) {
		int val = Q.top().first, input = Q.top().second, idx, idx_val;
		Q.pop();
		if (val_set.find(input) != val_set.end() && val >= val_set[input]) continue;
		val_set[input] = val;
		if (result_key == input) {
			continue;
		}

		for (i = 0; i < M; i++) {
			a = get<0>(CT[i]), b = get<1>(CT[i]), w = get<2>(CT[i]);
			int v1 = 1, v2 = 1;
			idx_val = input;
			for (j = 0; j < a - 1; j++, v1 *= 10);
			for (j = 0; j < b - 1; j++, v2 *= 10);
			a = idx_val / v1 % 10;
			b = idx_val / v2 % 10;
			idx_val -= a * v1;
			idx_val -= b * v2;
			idx_val += b * v1;
			idx_val += a * v2;
			Q.push({val + w, idx_val});
		}
	}
	cout << (val_set[result_key] == INT_MAX ? -1 : val_set[result_key]) << "\n";

	return 0;
}