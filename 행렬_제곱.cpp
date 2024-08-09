#include <bits/stdc++.h>

using namespace std;

int mat[5][5], dp[64][5][5], result[5][5];
// 0초기화

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, jj, kk, con = 1;
	long long M, iter;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> mat[i][j];
			dp[0][i][j] = mat[i][j] % 1000;
		}
	}
	for (i = 1, iter = M; iter > 0; iter /= 2, i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				for (l = 0; l < N; l++) {
					dp[i][j][k] += dp[i - 1][j][l] * dp[i - 1][l][k];
					dp[i][j][k] %= 1000;
				}
			}
		}
	}
	for (i = 0, iter = M; iter; iter /= 2, i++) {
		if (iter % 2 == 1) {
			if (con) {
				for (j = 0; j < N; j++) {
					for (k = 0; k < N; k++) {
						result[j][k] = dp[i][j][k];
						con = 0;
					}
				}
			} else {
				int copy[5][5];
				for (j = 0; j < N; j++) {
					for (k = 0; k < N; k++) {
						copy[j][k] = result[j][k];
						result[j][k] = 0;
					}
				}
				for (j = 0; j < N; j++) {
					for (k = 0; k < N; k++) {
						for (l = 0; l < N; l++) {
							result[j][k] += copy[j][l] * dp[i][l][k];
							result[j][k] %= 1000;
						}
					}
				}
			}
		}
	}
	for (j = 0; j < N; j++) {
		for (k = 0; k < N; k++) {
			cout << result[j][k] << " ";
		}
		cout << "\n";
	}
	return 0;
}