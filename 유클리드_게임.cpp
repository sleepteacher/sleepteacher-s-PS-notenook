#include <bits/stdc++.h>

using namespace std;

long long euc(long long a, long long b, bool res) {
	if (a % b == 0) {
		return res;
	} else if (a / b == 1) {
		return euc(b, a % b, !res);
	} else {
		if (euc(a % b + b, b, !res) == res || euc(b, a % b, !res) == res) {
			return res;
		} else {
			return !res;
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	long long a, b, i, j, k, l, iter;
	while (1) {
		cin >> a >> b;
		if (a == b && a == 0) {
			break;
		}
		if (a < b) {
			i = b;
			b = a;
			a = i;
		}

		if (euc(a, b, 1)) {
			cout << "A wins\n";
		} else
			cout << "B wins\n";
	}

	return 0;
}