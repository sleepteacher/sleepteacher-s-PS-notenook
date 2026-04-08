#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, TC, N, iter = 0;
	cin >> TC;
	while (iter++ != TC) {
		cin >> N;
		vector<int> V;
		for (i = 0; i < 2 * N; i++) {
			cin >> j;
			V.push_back(j);
		}
		cout << "Case #" << iter << ": ";
		k = 0;
		while (V.size()) {
			cout << V[0] << " ";
			for (j = 1; j < V.size(); j++) {
				if ((V[0] / 3) * 4 == V[j]) {
					V[j] = 1e9 + 1;
					break;
				}
			}
			V[0] = 1e9 + 1;
			sort(V.begin(), V.end());
			V.pop_back();
			V.pop_back();
		}
		cout << "\n";
	}

	return 0;
}