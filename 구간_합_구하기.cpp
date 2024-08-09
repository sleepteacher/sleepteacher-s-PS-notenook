#include <bits/stdc++.h>

using namespace std;

long long arr[1 << 23], seg_tree_val[1 << 23];

long long init(int start, int end, int idx) {
	int mid = (start + end) / 2;
	if (start == end)
		return seg_tree_val[idx] = arr[start];
	else
		return seg_tree_val[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}
long long get_val(int start, int end, int idx, int a, int b) {
	int mid = (start + end) / 2;
	if (a > end || b < start) {
		return 0;
	}
	if (a <= start && end <= b) {
		return seg_tree_val[idx];
	}
	return (long long)(get_val(start, mid, idx * 2, a, b) + get_val(mid + 1, end, idx * 2 + 1, a, b));
}
void insert(int start, int end, int idx, int insert_loca, long long diff) {
	int mid = (start + end) / 2;
	if (insert_loca < start || insert_loca > end) return;
	seg_tree_val[idx] = seg_tree_val[idx] + diff;
	if (start != end) {
		insert(start, mid, idx * 2, insert_loca, diff);
		insert(mid + 1, end, idx * 2 + 1, insert_loca, diff);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, K;
	long long a, b, c, diff;
	cin >> N >> M >> K;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init(1, N, 1);
	for (i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		// 1 - > b를 c로
		// 2 - > [b, c] 구간 출력
		if (a - 1) {
			cout << get_val(1, N, 1, b, c) << "\n";
		} else {
			diff = c - arr[b];
			arr[b] = c;
			insert(1, N, 1, b, diff);
		}
	}

	return 0;
}