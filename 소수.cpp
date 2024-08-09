#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, a, b, N, iter = 10, result;
	cin >> a >> b >> N;
	for (; iter < b; iter *= 10);
	a %= b;
	for (i = 0; i < N; i++) {
		a *= 10;
		result = a / b;
		a %= b;
	}
	cout << result << "\n";

	return 0;
}