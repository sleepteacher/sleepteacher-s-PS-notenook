#include <bits/stdc++.h>

using namespace std;

int recur(int N, int start, int mid, int to) {
	if (N == 1) {
		cout << start << " " << to << "\n";
		return 1;
	}
	recur(N - 1, start, to, mid);
	cout << start << " " << to << "\n";
	recur(N - 1, mid, start, to);
	return 1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N;
	cin >> N;
	cout << (1 << N) - 1 << "\n";
	recur(N, 1, 2, 3);

	return 0;
}