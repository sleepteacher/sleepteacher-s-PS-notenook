#include <bits/stdc++.h>

using namespace std;
int ip[1001], cash[101];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, T, iter = 0, con = 1;
	queue<int> arr[102], result;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> T;
		for (j = 0; j < T; j++) {
			cin >> k;
			arr[i].push(k);
			ip[k]++;
			iter++;
		}
	}
	while (con != 0) {
		con = 0;
		for (i = 0; i < M; i++) {
			if (cash[i] != 0 && ip[cash[i]] == 0) {
				cash[i] = 0, con++;
			}
			while (cash[i] == 0 && arr[i].size() > 0) {
				cash[i] = arr[i].front();
				arr[i].pop();
				ip[cash[i]]--, con++, iter--;
				if (ip[cash[i]] == 0) {
					result.push(cash[i]);
					cash[i] = 0;
				}
			}
		}
	}
	if (iter == 0) {
		while (!result.empty()) {
			cout << result.front() << "\n";
			ip[result.front()] = -1;
			result.pop();
		}
		for (i = 1; i <= N; i++) {
			if (ip[i] == 0) {
				cout << i << "\n";
			}
		}
	} else {
		cout << 0 << "\n";
	}
	return 0;
}