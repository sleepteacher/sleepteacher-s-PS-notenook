#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, a, b, c, result = 0, op = 2;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a;
		result = 0, op = 2;
		for (j = 2; j <= 100; j++) {
			k = a / j;
			if ((k * (k + 1)) / 2 * j > result) {
				result = (k * (k + 1)) / 2 * j;
				op = j;
			}
		}
		cout << op << "\n";
	}

	return 0;
}