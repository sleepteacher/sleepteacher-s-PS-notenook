#include <bits/stdc++.h>

using namespace std;

int UF[100001], visited[100001], cycle[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int i, j, k, l, T, N, result, start;
    cin >> T;
    for (i = 0; i < T; i++) {
        cin >> N;
        result = N;
        fill(visited, visited + N + 1, 0);
        fill(cycle, cycle + N + 1, 0);
        for (j = 1; j <= N; j++) {
            cin >> UF[j];
        }
        for (j = 1; j <= N; j++) {
            if (!cycle[j]) {
                if (visited[j] == 0) {
                    k = j;
                    while (!visited[k]) {
                        visited[k] = j;
                        k = UF[k];
                    }
                    while (!cycle[k] && visited[k] == j) {
                        cycle[k] = 1;
                        k = UF[k];
                        result -= 1;
                    }
                }
            }
        }
        cout << result << "\n";
    }
    return 0;
}

/*
1
11
2 10 4 5 6 7 8 9 2 2 11
혼 같2 혼 같1

*/