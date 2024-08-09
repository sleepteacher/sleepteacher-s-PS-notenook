#include <bits/stdc++.h>

#define MOD 1000000007L

using namespace std;

long long fact[4000001], pow_iter[100];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, iter = (int)(MOD - 2), N, R, TC;
	long long result;
	fact[0] = 1;
	for (i = 1; i <= 4000000; i++) {
		fact[i] = ((long long)i * fact[i - 1]) % MOD;
	}
	cin >> TC;
	while (TC--) {
		cin >> N >> R;
		result = ((fact[N - R] * fact[R]) % MOD);
		pow_iter[1] = result;
		iter = (int)(MOD - 2);
		iter /= 2;
		for (i = 2; i < 64; i++, iter /= 2) {
			if (iter == 0) break;
			pow_iter[i] = (pow_iter[i - 1] * pow_iter[i - 1]) % MOD;
			if (iter % 2) {
				result *= pow_iter[i];
				result %= MOD;
			}
		}
		result *= fact[N];
		result %= MOD;
		cout << result << "\n";
	}

	return 0;
}