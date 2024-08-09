#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> arr;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, a, b, result = 0, iter = 0;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		arr.push_back({a, b});
	}
	sort(arr.begin(), arr.end());
	pq.push(arr[0].second);
	for (i = 1; i < N; i++) {
		if (arr[i].first >= pq.top()) {
			pq.pop();
			pq.push(arr[i].second);
		} else {
			pq.push(arr[i].second);
		}
	}
	cout << pq.size() << "\n";

	return 0;
}