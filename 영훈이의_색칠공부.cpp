#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

unsigned long long d[100001];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	unsigned long long i, j, k, l, N, result = 1;
	cin >> N;
	d[0] = 1, d[1] = 0;
	for (i = 2; i <= N; i++) {
		result *= i;
		result %= MOD;
		d[i] = ((i - 1) * (d[i - 1] + d[i - 2])) % MOD;
	}
	cout << (result * d[N]) % MOD;

	return 0;
}