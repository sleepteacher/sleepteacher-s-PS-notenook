#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	vector<pair<unsigned long long, unsigned long long>> arr;
	unsigned long long N, M, iter, result = 0, i, j, k, l;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> j;
		k = arr.size();
		arr.push_back({1, j});
		for (l = 0; l < k; l++) {
			pair<unsigned long long, unsigned long long> val = arr[l];
			val.first++;
			val.second *= j;
			if (val.second < M) arr.push_back(val);
		}
	}
	result = 0;
	for (i = 0; i < arr.size(); i++) {
		unsigned long long a = arr[i].first, b = arr[i].second;
		if (a % 2) {
			result += M / b;
		} else {
			result -= M / b;
		}
	}
	cout << result << "\n";

	return 0;
}