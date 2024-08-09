#include <bits/stdc++.h>

using namespace std;

int EN[18];
bool ele[10];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, K, con = 1, L = 0, iter, comp, crash, val;
	unsigned long long N;
	cin >> N >> K;
	fill(EN, EN + 18, -1);
	for (i = 0; N > 0; N /= 10, i++) {
		EN[i] = N % 10;
	}
	L = i;
	if (L < K) {
		fill(EN, EN + 18, -1);
		L = K;
		EN[L - 1] = 1;
		EN[L - 2] = 0;
		for (i = 0, j = K - 1; j != 1; i++, j--) {
			EN[i] = j;
		}
	}
	while (con) {
		iter = 0;
		fill(ele, ele + 10, 0);
		for (i = 0; i < L; i++) ele[EN[i]] = 1;
		for (i = 0; i < 10; i++) iter += ele[i];
		if (iter == K) {
			for (i = L - 1; i >= 0; i--) {
				cout << EN[i];
			}
			con = 0;
		} else {
			fill(ele, ele + 10, 0);
			comp = L - K, iter = 0, crash = 0;
			for (i = L - 1; i >= 0; i--) {
				if (!ele[EN[i]]) {
					ele[EN[i]] = 1;
					iter += 1;
					if (iter > K) {
						crash = 1;
						break;
					}
				} else {
					if (comp) {
						comp--;
					} else {
						crash = 2;
						break;
					}
				}
			}
			if (crash) {
				val = 1;
				fill(ele, ele + 10, 0);
				for (j = L - 1; j > i; j--) ele[EN[j]] = 1;
				if (crash == 2) {
					for (j = EN[i] + 1; j < 10; j++) {
						if (!ele[j]) {
							val = 0;
							EN[i] = j;
							ele[j] = 1;
							for (j = 0; j < i; j++) EN[j] = 0;
							break;
						}
					}
					if (val) {
						while (1) {
							if (EN[i + 1] != 9) {
								EN[i + 1]++;
								for (j = 0; j <= i; j++) EN[j] = 0;
								break;
							} else {
								i++;
								if (L - 1 == i && EN[i] == 9) {
									L++, i++;
									EN[i] = 1;
									for (j = 0; j < i; j++) EN[j] = 0;
									break;
								}
							}
						}
					}
				} else {
					for (j = EN[i] + 1; j < 10; j++) {
						if (ele[j]) {
							val = 0;
							EN[i] = j;
							ele[j] = 1;
							for (j = 0; j < i; j++) EN[j] = 0;
							break;
						}
					}
					if (val) {
						while (1) {
							if (EN[i + 1] != 9) {
								EN[i + 1]++;
								for (j = 0; j <= i; j++) EN[j] = 0;
								break;
							} else {
								i++;
								if (L - 1 == i && EN[i] == 9) {
									L++, i++;
									EN[i] = 1;
									for (j = 0; j < i; j++) EN[j] = 0;
									break;
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}