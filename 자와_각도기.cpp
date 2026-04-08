#include <bits/stdc++.h>

using namespace std;

int v1[10], v2[10], sq[360];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, K, gcd = 0, term;
	cin >> N >> K;
	for (i = 0; i < N; i++) {
		cin >> v1[i];
		if (!gcd)
			gcd = v1[i];
		else
			gcd = v1[i] * gcd / __gcd(v1[i], gcd);
		gcd %= 360;
	}
	term = gcd;
	while (term && !sq[gcd]) {
		sq[gcd] = 1;
		gcd += term;
		gcd %= 360;
	}
	sq[gcd] = 1;
	for (i = 0; i < 360; i++) {
		if (sq[i] == 1) {
			for (j = 0; j < N; j++) {
				for (k = 1; k < 361; k++) {
					if (sq[(i + k * v1[j]) % 360] == 1) {
						break;
					} else {
						sq[(i + k * v1[j]) % 360] = 2;
					}
				}
			}
		}
	}
	for (i = 0; i < K; i++) {
		cin >> j;
		if (sq[j]) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
	}

	return 0;
}