#include <bits/stdc++.h>

using namespace std;

unsigned long long fibo[1000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, TC, fibo_size;
	set<unsigned long long> V[4];
	unsigned long long x;
	// cout << V[0].size() << " " << V[1].size() << " " << V[2].size() << " " << V[3].size() << "\n";
	fibo[1] = fibo[2] = 1;
	for (fibo_size = 3;; fibo_size++) {
		fibo[fibo_size] = fibo[fibo_size - 1] + fibo[fibo_size - 2];
		if (fibo[fibo_size] > 1e16) break;
	}
	for (i = 1; i < fibo_size; i++) {
		V[1].insert(fibo[i]);
		for (j = 1; j < fibo_size; j++) {
			V[2].insert(fibo[i] + fibo[j]);
			for (k = 1; k < fibo_size; k++) {
				V[3].insert(fibo[i] + fibo[j] + fibo[k]);
			}
		}
	}
	// cout << V[0].size() << " " << V[1].size() << " " << V[2].size() << " " << V[3].size() << "\n";
	cin >> TC;
	while (TC--) {
		cin >> k >> x;
		if (V[k].find(x) != V[k].end())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

	return 0;
}