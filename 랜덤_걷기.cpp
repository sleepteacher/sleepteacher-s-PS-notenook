#include <bits/stdc++.h>

#define MOD 1000000007L

using namespace std;

long long fact[4000001], pow_iter[100];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, iter, N, TC;
	long long result, val;
	fact[0] = 1;
	for (i = 1; i <= 2000000; i++) {
		fact[i] = ((long long)i * fact[i - 1]) % MOD;
	}
	cin >> TC;
	while (TC--) {
		cin >> N;
		iter = (int)(MOD - 2);
		result = (((fact[N] * fact[N]) % MOD) * (long long)(N + 1)) % MOD;
		fill(pow_iter, pow_iter + 100, 0);
		pow_iter[1] = result;
		iter /= 2;
		for (i = 2; i < 64; i++, iter /= 2) {
			pow_iter[i] = (pow_iter[i - 1] * pow_iter[i - 1]) % MOD;
			if (iter % 2) {
				result *= pow_iter[i];
				result %= MOD;
			}
		}
		result *= fact[N * 2];
		result %= MOD;
		cout << result << "\n";
	}

	return 0;
}