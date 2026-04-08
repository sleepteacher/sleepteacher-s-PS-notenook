#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, TC, N;
	cin >> TC;
	while (TC--) {
		cin >> N;
		if (N == 1)
			cout << -1;
		else if (N % 2 == 0)
			for (i = 0; i < N; i++) cout << 2;
		else {
			for (i = 1; i <= N / 2; i++) cout << i % 10;
			cout << --i % 10;
			for (; i > 0; i--) cout << i % 10;
		}
		cout << "\n";
	}

	return 0;
}