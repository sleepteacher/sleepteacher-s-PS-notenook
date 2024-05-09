#include <bits/stdc++.h>

using namespace std;

#define INF 1E8
int N, result = 0;
vector<vector<int>> arr(16, vector<int>(16, 0));
vector<vector<int>> dp(16, vector<int>(1 << 16, -1));

int solver(int now_city, int visited) {
    if (visited == (1 << N) - 1) {
        return arr[now_city][0] > 0 ? arr[now_city][0] : INF;
    }
    if (dp[now_city][visited] != -1) return dp[now_city][visited];
    dp[now_city][visited] = INF;
    for (int i = 0; i < N; i++) {
        if (((visited | 1 << i) != visited) && arr[now_city][i] != 0) {
            int iter = solver(i, (visited | (1 << i))) + arr[now_city][i];
            dp[now_city][visited] = min(iter, dp[now_city][visited]);
        }
    }
    return dp[now_city][visited];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int i, j, k, l, input;
    cin >> N;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    cout << solver(0, 1) << "\n";

    return 0;
}