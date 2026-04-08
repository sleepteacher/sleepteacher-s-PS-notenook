#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, result = 0, con = 1;
	vector<int> a, b;
	cin >> N;
	a = vector<int>(N, 0);
	b = vector<int>(N, 0);
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	while (con) {
		b = vector<int>(N, 0);
		for (i = 0; i < N; i++) {
			for (j = i + 1; j < N; j++) {
				if (a[i] < a[j]) b[i]++;
			}
		}
		con = 0;
		for (i = 0; i < N * (con == 0); i++) {
			if (a[i] != b[i]) con = 1;
		}
		if (con) a = b;
		result++;
	}
	cout << result;

	return 0;
}
/*
1 2 3 2 1 0
2 1 0 0 0 0
0 0 0 0 0 0
*/