#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int i, j, k, l, N, result = 1;
    cin >> N;
    vector<int> arr1(N), arr2(N), visited(1000001, 0);

    for (i = 0; i < N; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    sort(arr1.begin(), arr1.end());
    for (i = N - 1; i >= 0; i--) {
        visited[arr2[i]]++;
        j = upper_bound(arr1.begin(), arr1.end(), arr2[i]) - arr1.begin() -
            visited[arr2[i]];
        k = abs(j - i) + 1;
        j = N - j;
        result = max(min({j, k}), result);
    }

    cout << result;

    return 0;
}