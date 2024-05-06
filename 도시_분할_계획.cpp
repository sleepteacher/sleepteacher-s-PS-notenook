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
    int i, j, k, l, N, M, a, b, c, last = 0,result = 0;
    cin >> N >> M;
    for (i = 1; i <= N; i++) {
        cin >> a ;
        UF[i] = a;
    }
    for (i = 0; i < M; i++) {
        
        G[c].push_back({a, b});
        
    }
    

    return 0;
}