#include <bits/stdc++.h>

using namespace std;
vector<int> info[100001];
queue<int> Q;
int dp[100001][17], depth[100001];
bool visited[100001];
int LCA(int a, int b) {
    int i, j, k, l, dif, iter;
    if (depth[a] < depth[b]) {
        i = a;
        a = b;
        b = i;
    }
    dif = depth[a] - depth[b], iter;
    for (i = 0; i < 17; i++) {
        iter = 1 << i;
        if ((dif | iter) == dif) {
            a = dp[a][i];
        }
    }
    if (a != b) {
        for (i = 16; i >= 0; i--) {
            if ((dp[a][i] != 0) && (dp[a][i] != dp[b][i])) {
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        a = dp[a][0];
    }
    return a;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int i, j, k, l, T, N, a, b;

    fill(visited, visited + 100001, 1);
    cin >> N;
    info[1].push_back(0);
    dp[1][0] = 0, depth[1] = 1, visited[0] = 0;
    for (i = 0; i < N - 1; i++) {
        cin >> a >> b;
        info[a].push_back(b);
        info[b].push_back(a);
    }
    Q.push(1);
    while (!Q.empty()) {
        int vertex = Q.front();
        Q.pop();
        visited[vertex] = 0;
        for (i = 0; i < info[vertex].size(); i++) {
            int now = info[vertex][i];
            if (visited[now]) {
                depth[now] = depth[vertex] + 1;
                dp[now][0] = vertex;
                for (j = 0; j < 16; j++) {
                    if (dp[dp[now][j]][j] != 0) {
                        dp[now][j + 1] = dp[dp[now][j]][j];
                    }
                }
                Q.push(now);
            }
        }
    }
    cin >> T;
    for (i = 0; i < T; i++) {
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
        // LCA(a, b);
    }

    return 0;
}