#include <bits/stdc++.h>

using namespace std;

int dp[51][51], dx[3] = {0, 1, -1}, dy[3] = {-1, -1, 0};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	vector<string> a(50);
	int i, j, k, l, N, result = 0, iter;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	/*
	간섭 영역
	1,1 기준
	0,1 0,2
	1,0 1,2
	2,0 2,1
	dp[y-1][x], dp[y-1][x+1],dp[y][x-1], dp[y][x+1], dp[y+1][x-1],dp[y+1][x]
	풀이 방식 -> x축 기준 1자로 탐색함. 따라서 dp[y-1][x], dp[y-1][x+1],dp[y][x-1] 영역만 탐색함.
	*/
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (a[i][j] == 'X') {
				set<int> pp;
				iter = 0;
				for (k = 0; k < 3; k++) {
					if (i + dy[k] < 0 || j + dx[k] < 0 || j + dx[k] == N) continue;
					pp.insert(dp[i + dy[k]][j + dx[k]]);
				}
				iter = pp.size() + 1;
				if (pp.find(0) != pp.end()) {
					iter--;
				}
				if (iter > result) {
					result++;
					dp[i][j] = result;
				} else {
					for (k = 1; k <= iter; k++) {
						if (pp.find(k) == pp.end()) {
							dp[i][j] = k;
							break;
						}
					}
				}
			}
		}
    }
	cout << result << "\n";
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}