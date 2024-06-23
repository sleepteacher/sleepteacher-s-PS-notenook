#include <bits/stdc++.h>

using namespace std;

long long mat[5][5], dp[64][5][5], result[5][5];
// 0초기화

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, jj, kk, con = 1;
	long long M, iter, ans = 0;
	cin >> M;
	M--;
	N = 5;
	if (M == 0) {
		cout << 5 << "\n";
		return 0;
	}
	mat[0][0] = 0, mat[0][1] = 1, mat[0][2] = 1, mat[0][3] = 1, mat[0][4] = 1;
	mat[1][0] = 1, mat[1][1] = 0, mat[1][2] = 0, mat[1][3] = 1, mat[1][4] = 1;
	mat[2][0] = 1, mat[2][1] = 0, mat[2][2] = 0, mat[2][3] = 0, mat[2][4] = 1;
	mat[3][0] = 1, mat[3][1] = 1, mat[3][2] = 0, mat[3][3] = 0, mat[3][4] = 0;
	mat[4][0] = 1, mat[4][1] = 1, mat[4][2] = 1, mat[4][3] = 0, mat[4][4] = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			dp[0][i][j] = mat[i][j];
		}
	}
	for (i = 1, iter = M; iter > 0; iter /= 2, i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				for (l = 0; l < N; l++) {
					dp[i][j][k] += dp[i - 1][j][l] * dp[i - 1][l][k];
					dp[i][j][k] %= 1000000007;
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
							result[j][k] %= 1000000007;
						}
					}
				}
			}
		}
	}
	for (j = 0; j < N; j++) {
		for (k = 0; k < N; k++) {
			ans += result[j][k];
			ans %= 1000000007;
		}
	}
	cout << ans << "\n";
	return 0;
}