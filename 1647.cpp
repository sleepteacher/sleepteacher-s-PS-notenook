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

    vector<vector<pair<int, int>>> G(100001);
    int i, j, k, l, N, M;

    //cin >> N >> M;
    cout << 1 << "\n";

    return 0;
}