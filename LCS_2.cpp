#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    vector<vector<int>> dp(1001, vector<int>(1001, 0));
    stack<char> result;
    string a, b;
    int i, j, k, l, x, y;
    cin >> a >> b;
    for (i = 1; i <= a.size(); i++) {
        int val_a = a[i - 1] - 'A';
        for (j = 1; j <= b.size(); j++) {
            int val_b = b[j - 1] - 'A';
            if (val_a == val_b) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    i--, j--;
    cout << dp[i][j] << "\n";
    while (i > 0 || j > 0) {
        if (dp[i][j - 1] == dp[i][j])
            j--;
        else if (dp[i - 1][j] == dp[i][j])
            i--;
        else {
            i--, j--;
            result.push(a[i]);
        }
    }
    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }

    return 0;
}