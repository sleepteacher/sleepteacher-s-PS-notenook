#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, inp, result = 0, iter = 3;
	
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> inp;
		inp -= iter / 2;
		while (iter <= inp) {
			if (inp % iter == 0) {
				result--;
				break;
			}
			inp--, iter += 2;
		}
		result++;
	}
	cout << result << "\n";

	return 0;
}