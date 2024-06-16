#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, cnt, cd_iter, ab_iter, ab_eq, cd_eq, ab_eq_size, cd_eq_size, con;
	long long result = 0;
	cin >> N;
	vector<int> a(N), b(N), c(N), d(N), ab(N * N), cd;
	for (i = 0; i < N; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	cnt = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			ab[cnt++] = a[i] + b[j];
		}
	}
	sort(ab.begin(), ab.end());
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (c[i] + d[j] < 0) {
				if (c[i] + d[j] + ab[N * N - 1] >= 0) {
					cd.push_back(c[i] + d[j]);
				}
			} else {
				if (c[i] + d[j] + ab[0] <= 0) {
					cd.push_back(c[i] + d[j]);
				}
			}
		}
	}
	if (!cd.size()) {
		cout << 0;
		return 0;
	}
	sort(cd.begin(), cd.end(), greater<int>());

	// ab 오름차순
	// cd 내림차순
	ab_iter = 0, cd_iter = 0, ab_eq_size = 0, cd_eq_size = 0;
	ab_eq = ab[ab_iter], cd_eq = cd[cd_iter];
	while (1) {
		if (ab_eq + cd_eq == 0) {
			con = 0;
		} else if (ab_eq + cd_eq < 0) {
			con = 1;
		} else {
			con = 2;
		}
		while (ab_iter < ab.size() && ab[ab_iter] == ab_eq) {
			ab_iter++, ab_eq_size++;
		}
		while (cd_iter < cd.size() && cd[cd_iter] == cd_eq) {
			cd_iter++, cd_eq_size++;
		}

		if (!con) {
			result += (long long)ab_eq_size * (long long)cd_eq_size;
			ab_eq = ab[ab_iter], cd_eq = cd[cd_iter];
			ab_eq_size = 0, cd_eq_size = 0;
			if (ab_iter == ab.size()) break;
			if (cd_iter == cd.size()) break;
		} else {
			if (con == 1) {
				ab_eq = ab[ab_iter], ab_eq_size = 0;
				if (ab_iter == ab.size()) break;
			} else {
				cd_eq = cd[cd_iter], cd_eq_size = 0;
				if (cd_iter == cd.size()) break;
			}
		}
	}
	cout << result << "\n";

	return 0;
}