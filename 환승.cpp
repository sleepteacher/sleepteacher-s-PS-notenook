#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr, tmp;
int visited[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, K, M, iter, change_val, cnt;
	cin >> N >> K >> M;
	fill(visited, visited + 100001, INT_MAX);
	visited[1] = 1;
	for (i = 0; i < M; i++) {
		arr.push_back({});
		int idx = arr.size() - 1;
		for (j = 0; j < K; j++) {
			cin >> k;
			arr[idx].push_back(k);
		}
		sort(arr[idx].begin(), arr[idx].end());
		if (arr[idx][0] == 1) {
			for (j = 1; j < K; j++) {
				visited[arr[idx][j]] = 2;
			}
			arr.pop_back();
		}
	}
	tmp = arr;
	for (int now_change = 3; now_change < 1010; now_change++) {
		arr = tmp, tmp.resize(0), cnt = 0;
		for (i = 0; i < arr.size(); i++) {
			change_val = INT_MAX;
			for (j = 0; j < K; j++) {
				change_val = min(visited[arr[i][j]], change_val);
			}
			if (change_val >= now_change) {
				tmp.push_back(arr[i]);
				continue;
			}
			change_val++;
			for (j = 0; j < K; j++) {
				visited[arr[i][j]] = min(change_val, visited[arr[i][j]]);
			}
			if (now_change < change_val) {
				tmp.push_back(arr[i]);
			} else {
				cnt++;
			}
		}
		if (!cnt) break;
	}
	if (visited[N] == INT_MAX) {
		cout << -1 << "\n";
	} else {
		cout << visited[N] << "\n";
	}

	return 0;
}