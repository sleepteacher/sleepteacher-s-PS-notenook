#include <bits/stdc++.h>

using namespace std;

int arr[720][702];
bool visited[702];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	long long N, K, M, i, j, k, l, start = '[' - 45, sw, con = 0, cycle_start = 0;
	string input = "", f_op = "[", loop = "";

	cin >> N >> K >> M;
	for (i = 0; i < N; i++) {
		cin >> input;
		for (j = 0; j < input.size() - 1; j++) {
			int val = input[j + 1] - '-';
			arr[input[j] - '-'][val]++;
		}
	}
	for (i = 0; i < 29; i++) {
		if (!visited[start]) {
			visited[start] = 1;
			sw = 71;
			for (j = 70; j > -1; j--) {
				if (arr[start][sw] <= arr[start][j]) {
					sw = j;
				}
			}
			char L = (char)('-' + sw);
			f_op += L;
			start += sw + '-';
			if (sw + '-' != ']') {
				start = sw;
			} else {
				con = 1;
				break;
			}
		} else {
			break;
		}
	}
	fill(visited, visited + 702, 0);
	for (i = 0; i < 29; i++) {
		if (!visited[start]) {
			visited[start] = 1;
			sw = 100;
			for (j = 99; j > -1; j--) {
				if (arr[start][sw] <= arr[start][j]) {
					sw = j;
				}
			}
			char L = (char)('-' + sw);
			loop += L;
			start += sw + '-';
			if (sw + '-' != ']') {
				start = sw;
			} else {
				con = 1;
				break;
			}
		} else {
			break;
		}
	}

	if (con) {
		for (i = K - 1; i < K + M - 1; i++) {
			if (f_op.size() > i) {
				cout << f_op[i];
			} else {
				cout << ".";
			}
		}
	} else {
		if (K < f_op.size()) {
			for (i = K - 1; i < K + M - 1; i++) {
				if (f_op.size() > i) {
					cout << f_op[i];
				} else {
					cout << loop[(i - f_op.size()) % loop.size()];
				}
			}
		} else {
			K -= f_op.size();
			K = (K - 1) % loop.size();
			for (i = K; i < K + M; i++) {
				cout << loop[i % loop.size()];
			}
		}
	}

	return 0;
}