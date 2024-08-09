#include <bits/stdc++.h>

using namespace std;

unsigned long long mat[8][8] = {
	// 0 1 2 3 4 5 6 7
	{0, 1, 0, 1, 0, 0, 0, 0},  // 0
	{1, 0, 1, 0, 0, 0, 0, 0},  // 1
	{0, 1, 0, 1, 1, 1, 0, 0},  // 2
	{1, 0, 1, 0, 1, 0, 0, 0},  // 3
	{0, 0, 1, 1, 0, 1, 1, 0},  // 4
	{0, 0, 1, 0, 1, 0, 1, 1},  // 5
	{0, 0, 0, 0, 1, 1, 0, 1},  // 6
	{0, 0, 0, 0, 0, 1, 1, 0},  // 7
},
				   dp[64][8][8], result[8][8];
// 0초기화

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	unsigned long long i, j, k, l, N, jj, kk, con = 1;
	unsigned long long M, iter, op = 0;
	cin >> M;
	N = 8;

	/*
	0 1
	0 3
	1 2
	2 3
	2 4
	2 5
	3 4
	4 5
	4 6
	5 6
	5 7
	6 7
	*/
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			dp[0][i][j] = mat[i][j] % 1000000007;
		}
	}
	for (i = 1; i < 50; i++) {
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				for (l = 0; l < N; l++) {
					dp[i][j][k] += dp[i - 1][j][l] * dp[i - 1][l][k];
					dp[i][j][k] %= 1000000007;
				}
			}
		}
	}
	for (i = 0, iter = M; i < 64; i++) {
		if (iter % 2 == 1) {
			if (con) {
				for (j = 0; j < N; j++) {
					for (k = 0; k < N; k++) {
						result[j][k] = dp[i][j][k];
						con = 0;
					}
				}
			} else {
				unsigned long long copy[8][8];
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
		iter /= 2;
	}
	op += result[7][7];
	op %= 1000000007;
	cout << op << "\n";
	return 0;
}
/*
학생회관 0
형남이 1
진리 2
한경 3
신양 4
미래 5
전산 6
정보 7
0 1 1 0 0 0 0 0
1 0 0 1 0 0 0 0
1 0 0 1 1 0 0 0
0 1 1 0 1 1 0 0
0 0 1 1 0 1 1 0
0 0 0 1 1 0 1 1

0 0 0 0 1 1 0 1

0 0 0 0 0 1 1 0

mat[0][0] = 0, mat[0][1] = 1, mat[0][2] = 1, mat[0][3] = 0, mat[0][4] = 0, mat[0][5] = 0, mat[0][6] = 0, mat[0][7] = 0;
mat[1][0] = 1, mat[1][2] = 0, mat[1][2] = 0, mat[1][3] = 1, mat[1][4] = 0, mat[1][5] = 0, mat[1][6] = 0, mat[1][7] = 0;
mat[2][0] = 1, mat[2][2] = 0, mat[2][2] = 0, mat[2][3] = 1, mat[2][4] = 1, mat[2][5] = 0, mat[2][6] = 0, mat[2][7] = 0;
mat[3][0] = 0, mat[3][2] = 1, mat[3][2] = 1, mat[3][3] = 0, mat[3][4] = 1, mat[3][5] = 1, mat[3][6] = 0, mat[3][7] = 0;
mat[4][0] = 0, mat[4][2] = 0, mat[4][2] = 1, mat[4][3] = 1, mat[4][4] = 0, mat[4][5] = 1, mat[4][6] = 1, mat[4][7] = 0;
mat[5][0] = 0, mat[5][2] = 0, mat[5][2] = 0, mat[5][3] = 1, mat[5][4] = 1, mat[5][5] = 1, mat[5][6] = 0, mat[5][7] = 1;
mat[6][0] = 0, mat[6][2] = 0, mat[6][2] = 0, mat[6][3] = 0, mat[6][4] = 1, mat[6][5] = 1, mat[6][6] = 0, mat[6][7] = 1;
mat[7][0] = 0, mat[7][2] = 0, mat[7][2] = 0, mat[7][3] = 0, mat[7][4] = 0, mat[7][5] = 1, mat[7][6] = 1, mat[7][7] = 0;



*/