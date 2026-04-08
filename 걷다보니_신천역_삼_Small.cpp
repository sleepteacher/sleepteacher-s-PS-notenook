#include <bits/stdc++.h>

using namespace std;

int dfs(string S, int depth) {
	if (!depth) {
		return stoi(S) % 3 == 0;
	} else {
		return dfs(S + "0", depth - 1) + dfs(S + "1", depth - 1) + dfs(S + "2", depth - 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	cout << dfs("1", N - 1) + dfs("2", N - 1);

	return 0;
}