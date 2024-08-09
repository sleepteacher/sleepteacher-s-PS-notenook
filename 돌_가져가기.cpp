#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, W = 0, B = 0, con = 1;
	vector<pair<int, char>> arr;
	long long result = 0;
	string input;
	cin >> N;
	cin >> input;
	for (i = 0; i < N; i++) {
		cin >> j;
		if (arr.size() && arr[arr.size() - 1].second == input[i]) {
			if (arr[arr.size() - 1].first < j) {
				arr.pop_back();
				arr.push_back({j, input[i]});
			}
		} else {
			arr.push_back({j, input[i]});
		}
	}
	if (arr.begin() + 1 < arr.end() - 1) {
		sort(arr.begin() + 1, arr.end() - 1, greater<pair<int, char>>());
		for (i = 1; i <= (arr.size() - 1) / 2; i++) {
			result += arr[i].first;
		}
	}

	cout << result;

	return 0;
}