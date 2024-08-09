#include <bits/stdc++.h>

using namespace std;

int arr[100000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, L, R, result_val = INT_MAX, result_arr[2];
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	L = 0, R = N - 1;
	while (L < R) {
		if (abs(arr[L] + arr[R]) < result_val) {
			result_arr[0] = min(arr[L], arr[R]), result_arr[1] = max(arr[L], arr[R]);
			result_val = abs(arr[L] + arr[R]);
			if (result_val == 0) break;
		}
		if (arr[L] + arr[R] < 0) {
			L++;
		} else {
			R--;
		}
	}
	cout << result_arr[0] << " " << result_arr[1];

	return 0;
}