#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N;
	long long result, iter;
	while (1) {
		cin >> N;
		iter = 0;
		l = INT_MIN;
		result = LLONG_MIN;
		if (!N) break;
		for (i = 0; i < N; i++) {
			cin >> j;
			l = max(j, l);
			if (j + iter < 0) {
				iter = 0;
			} else {
				iter += j;
				result = max(result, iter);
			}
		}
		result = max(result, (long long)l);
		cout << result << "\n";
	}

	return 0;
}