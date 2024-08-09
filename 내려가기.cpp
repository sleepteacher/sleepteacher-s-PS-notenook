#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, a, b, c;
	pair<int, int> arr[3], front[3];
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b >> c;
		arr[0].first = max(front[0].first, front[1].first) + a;
		arr[1].first = max({front[0].first, front[1].first, front[2].first}) + b;
		arr[2].first = max(front[1].first, front[2].first) + c;
		arr[0].second = min(front[0].second, front[1].second) + a;
		arr[1].second = min({front[0].second, front[1].second, front[2].second}) + b;
		arr[2].second = min(front[1].second, front[2].second) + c;
		copy(arr, arr + 3, front);
	}
	cout << max({arr[0].first, arr[1].first, arr[2].first}) << " " << min({arr[0].second, arr[1].second, arr[2].second});
	return 0;
}