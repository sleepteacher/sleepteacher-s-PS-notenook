#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, a, b;
	long long result = 0;
	cin >> N;
	for (i = 2; 0 < (N / i - i + 1); i++) {
		result += (long long)(i * (N / i - i + 1)) % 1000000 + (((i + 1 + N / i) * (long long)(N / i - i)) / 2) % 1000000;
		result %= 1000000;
	}
	cout << result << "\n";

	return 0;
}
