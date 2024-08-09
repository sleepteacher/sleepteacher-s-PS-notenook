#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int TC, N, M, i, j, k, l, iter, L, R;
	long long result;
	cin >> TC;
	for (iter = 1; iter <= TC; iter++) {
		cin >> N;
		L = 0, R = N - 1;
		result = 0;
		vector<int> arr(N);
		vector<pair<int, int>> parr;
		for (i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		for (i = 0; i < N / 4; i++, L++, R--) {
			parr.push_back({arr[L], arr[R]});
		}
		for (i = 0; i < N / 4; i++, L++, R--) {
			result += abs(parr[i].second - arr[R]) + abs(arr[R] - arr[L]) + abs(arr[L] - parr[i].first) + abs(parr[i].first - parr[i].second);
		}
		cout << "Case #" << iter << "\n";
		cout << result << "\n";
	}

	return 0;
}