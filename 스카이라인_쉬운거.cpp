#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, x, y, result = 0, con;
	vector<int> L;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x >> y;
		if (y) {
			if (!L.size()) {
				L.push_back(y);
				result++;

			} else {
				con = 1;
				while (L.size()) {
					if (L[L.size() - 1] > y) {
						L.pop_back();
					} else if (L[L.size() - 1] < y) {
						break;
					} else {
						con = 0;
						break;
					}
				}
				if (con) {
					L.push_back(y);
					result++;
				}
			}
		} else {
			L.resize(0);
		}
	}

	cout << result << "\n";
	return 0;
}