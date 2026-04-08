#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	long long i, j, k, l, a, b, dp = 1, iter = 0, result = 1;
	cin >> a >> b;
	iter = b;
	dp = a;
	if (a == 1) {
		cout << b % 1000000007;
	} else {
		for (i = 0; i < 64; i++) {
			if (iter % 2) {
				result = (result * dp) % 1000000007;
			}
			dp = (dp * dp) % 1000000007;
			iter /= 2;
		}
		/*
		sum(A^0 to A^B-1) mod p = (k+pa)/(A-1) mod p
		A ^ B - 1 mod p == k mod p
		*/
		result -= 1;
		if (result < 0) result += 1000000007;
		if (result % (a - 1) == 0) {
			cout << result / (a - 1) << "\n";
		} else {
			for (i = 1;; i++) {
				if ((result + i * (1000000007)) % (a - 1) == 0) {
					cout << ((result + i * (1000000007)) / (a - 1));
					break;
				}
			}
		}
	}

	return 0;
}