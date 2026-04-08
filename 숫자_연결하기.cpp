#include <bits/stdc++.h>

using namespace std;

bool visited[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	long long i, j, k, l, N, K, val, NK, iter, res = 1, con = 0, mul_iter;
	cin >> N >> K;
	for (iter = 10; iter <= N; iter *= 10);

	iter %= K;
	NK = N % K;
	mul_iter = iter;
	val = NK;

	while (val) {
		if (!visited[val]) {
			visited[val] = 1;
			val += NK * mul_iter;
			val %= K;
			mul_iter *= iter;
			mul_iter %= K;
			res++;
		} else {
			con++;
			break;
		}
	}
	if (con) {
		cout << -1;
	} else {
		cout << res;
	}

	return 0;
}