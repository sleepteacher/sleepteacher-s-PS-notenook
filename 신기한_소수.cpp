#include <bits/stdc++.h>

using namespace std;

int isprime(int val) {
	if (val == 0 || val == 1) return 0;
	for (int i = 2; i * i <= val; i++) {
		if (val % i == 0) return 0;
	}
	return 1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, start = 1, end = 1, TN, iter, rec, con;
	cin >> N;
	for (i = 0; i < N; i++) {
		end *= 10;
	}
	start = end / 10;
	TN = start;
	iter = TN, rec = (start / TN) % 10, con = 1;
	cout << TN << " " << rec << "\n";
	start = 2333;
	while (start < end) {
		iter = TN, rec = (start / TN) % 10, con = 1;
		while (0 < iter) {
			if (isprime((start / iter)) == 0) {
				start += iter;
				rec++;

			} else {
				iter /= 10;
				rec = (start / iter) % 10;
			}
			if (rec == 10) {
				con = 0;
				break;
			}
		}

		if (con) cout << start << "\n";
		break;
	}

	return 0;
}