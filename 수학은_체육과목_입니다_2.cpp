#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, iter = 1, con = -1;
	cin >> N;
	for (i = 0; i < N - 1; i++) {
		if (iter == 1 && con == -1) {
			con *= -1;
		} else if (iter == 5 && con == 1) {
			con *= -1;
		}
		iter = (iter + 1 * con);
	}
	cout << iter;

	return 0;
}