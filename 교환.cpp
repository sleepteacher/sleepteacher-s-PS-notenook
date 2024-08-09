#include <bits/stdc++.h>

using namespace std;
bool visited[10][1000001];
int L;
int mul(int i, int j) {
	if (!j) return 1;
	return i * mul(i, j - 1);
}
int DFS(int x, int y, int value, int iter) {
	int a = ((value / mul(10, x)) % 10), b = ((value / mul(10, y)) % 10), i, j, k, l, result = -1, val = value;
	if (y == L - 1 && a == 0) {
		return -1;
	}
	val -= a * mul(10, x) + b * mul(10, y);
	val += a * mul(10, y) + b * mul(10, x);
	// cout << val << "\n";
	iter--;
	if (visited[iter][val]) {
		return -1;
	} else {
		visited[iter][val] = 1;
	}
	if (iter == 0) return val;
	for (i = 0; i < L; i++) {
		for (j = i + 1; j < L; j++) {
			result = max(DFS(i, j, val, iter), result);
		}
	}
	return result;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, K, result = -1;
	cin >> N >> K;
	for (L = 0; L < 10; L++) {
		if (mul(10, L) > N) break;
	}
	for (i = 0; i < L; i++) {
		for (j = i + 1; j < L; j++) {
			result = max(DFS(i, j, N, K), result);
		}
	}
	cout << result << "\n";

	return 0;
}