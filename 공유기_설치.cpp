#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, left, right, mid, iter, idx, next_idx, result;
	vector<int> arr;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> j;
		arr.push_back(j);
	}
	sort(arr.begin(), arr.end());
	left = arr[0], right = arr[N - 1] - arr[0];
	while (left < right) {
		mid = (left + right + 1) / 2, iter = 1, idx = 0, result = mid;
		while (idx != arr.end() - arr.begin()) {
			next_idx = lower_bound(arr.begin() + idx + 1, arr.end(), mid) - arr.begin();
			if (next_idx < arr.end() - arr.begin()) {
				iter++, result = ;
			}
		}
	}

	return 0;
}