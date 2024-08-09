#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, L, C, K, left, right, result = 0, mid, start, end, seg_start, seg_end;
	vector<int> arr;
	cin >> L >> K >> C;
	arr.resize(K);
	for (i = 0; i < K; i++) {
		cin >> arr[i];
	}
	/*
	자를 수 있는 위치
	*/
	sort(arr.begin(), arr.end());
	left = arr[0], right = arr[K - 1];
	while (left < right) {
		mid = (left + right + 1) / 2;
		start = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
		if (arr[start] != mid)
			start--;
			
	}
	cout << left;

	return 0;
}