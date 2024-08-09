#include <bits/stdc++.h>

using namespace std;

unsigned long long jegop(unsigned long long a, unsigned long long x) {
	if (x == 0) return 1;
	return a * jegop(a, x - 1);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	unsigned long long in, iter, result, root = 0, origin;
	cin >> in;
	origin = in;
	result = 0;
	for (iter = 2; (iter - 1) * (iter - 1) <= origin; iter++) {
		root = 0;
		while (in % iter == 0) {
			root++;
			in /= iter;
		}
		if (root > 0) {
			if (result) {
				result *= (jegop(iter, root) - jegop(iter, root - 1));
			} else {
				result = (jegop(iter, root) - jegop(iter, root - 1));
			}
		}
	}
	if (result != 0 && in != 1) result *= in - 1;
	if (result == 0 && in != 1) result = in - 1;
	if (origin == 1) result = 1;

	cout << result << "\n";

	return 0;
}