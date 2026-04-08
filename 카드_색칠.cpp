#include <stdio.h>
#include <std

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int dp[3];
char str[2000001];

int main() {
	int i, j, k, l, N, a, b, ii, jj, kk, ll;
	char p;

	scanf("%d", &N);
	getchar();
    for (i = 1; i <= N + 1; i++) {
		ii = i % 3, jj = (i - 1) % 3, kk = (i - 2) % 3;
		if (i <= N) {
			dp[ii] = getchar() - '0';
			getchar();
		}
		if (i >= 2) {
			a = min(dp[kk], dp[ii]), b = max(dp[kk], dp[ii]);
			ll = max(1, ((b + 1) % 4));
			dp[kk] = 0;
			if (!dp[jj]) {
				dp[jj] = ll + (a == ll);
			} else if (a == dp[jj] || b == dp[jj]) {
				printf("-1");
				return 0;
			}
			str[(i - 2) * 2] = ('0' + dp[(i - 1) % 3]);
			str[(i - 2) * 2 + 1] = ' ';
		}
	}
	printf("%s", str);

	return 0;
}