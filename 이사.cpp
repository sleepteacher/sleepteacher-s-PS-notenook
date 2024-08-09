#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> arr;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, a, b, c, P;
	tuple<int, int, int> result = {1e9, 0, 0}, short_result;
	double x, y;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back({a, b});
	}
	for (i = 0; i < N; i++) {
		short_result = {0, 0, 0};
		for (j = 0; j < N; j++) {
			if (j != i) {
				P = (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second);
				if (P > get<0>(short_result)) {
					short_result = {P, i, j};
				}
			}
		}
		if (get<0>(short_result) < get<0>(result)) {
			result = short_result;
		}
	}
	tie(a, b, c) = result;
	x = (double)arr[b].first, y = (double)arr[b].second;
	// cout << b << " " << c << "\n";
	// cout << arr[c].first << " " << arr[c].second << "\n";
	cout << x << " " << y << "\n";
	return 0;
}