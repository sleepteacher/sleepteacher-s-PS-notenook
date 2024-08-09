#include <bits/stdc++.h>

using namespace std;

int UF[201];

int UF_find(int a) {
	if (UF[a] == a) return a;
	return UF[a] = UF_find(UF[a]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, con = 0;
	cin >> N >> M;
	for (i = 1; i <= N; i++) UF[i] = i;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> k;
			if (k && UF_find(i) != UF_find(j)) {
				UF[UF_find(j)] = UF_find(i);
			}
		}
		// cout << "\n";
	}
	for (i = 0; i < M; i++) {
		cin >> j;
		// cout << j << " ";
		if (i) {
			if (UF_find(k) != UF_find(j)) {
				con = 1;
				break;
			}
		} else {
			k = j;
		}
	}
	// cout << "\n";
	if (con)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}