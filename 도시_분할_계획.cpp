#include <bits/stdc++.h>

using namespace std;

int UF[100001];
int UF_find(int a) {
    if (UF[a] != a) {
        return UF[a] = UF_find(UF[a]);
    }
    return a;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<vector<pair<int, int>>> G(1001);
    int i, j, k, l, N, M, a, b, c, last = 0, result = 0;
    cin >> N >> M;
    for (i = 1; i <= N; i++) {
        UF[i] = i;
    }
    for (i = 0; i < M; i++) {
        cin >> a >> b >> c;
        G[c].push_back({a, b});
    }
    for (i = 1; i < 1001; i++) {
        for (j = 0; j < G[i].size(); j++) {
            if (UF_find(G[i][j].first) != UF_find(G[i][j].second)) {
                last = i;
                result += i;
                UF[UF_find(G[i][j].first)] = UF_find(G[i][j].second);
            }
        }
    }
    cout << result - last << "\n";

    return 0;
}