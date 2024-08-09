#include <bits/stdc++.h>

using namespace std;

int arr[26];

int dfs(int mo, int ja, int start, int size, vector<int> &result) {
	int N, M, i, j, k, l;
	if (mo + ja == size) {
		if (mo >= 1 && ja >= 2) {
			char in = 'a';
			for (i = 0; i < 26; i++) {
				if (result[i]) {
					cout << in;
				}
				in++;
			}
			cout << "\n";
		}
		return 0;
	}
	if (start >= 26) return 0;
	for (i = start; i < 26; i++) {
		if (!arr[i]) continue;
		result[i] = 1;
		if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
			dfs(mo + 1, ja, i + 1, size, result);
		} else {
			dfs(mo, ja + 1, i + 1, size, result);
		}
		result[i] = 0;
	}
	return 0;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	char input;
	int N, M, i, j, k, l;
	vector<int> result(26, 0);
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> input;
		arr[input - 'a']++;
	}
	for (i = 0; i < 26; i++) {
		if (!arr[i]) continue;
		result[i] = 1;
		if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
			dfs(1, 0, i + 1, N, result);
		} else {
			dfs(0, 1, i + 1, N, result);
		}
		result[i] = 0;
	}
	return 0;
}