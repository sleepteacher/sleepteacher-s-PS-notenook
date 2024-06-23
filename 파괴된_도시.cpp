#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> graph[2001];
bool alive[2001], fun_alive[2001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, a, b, con;
	vector<int> result;

	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	cin >> K;
	for (i = 0; i < K; i++) {
		cin >> a;
		alive[a] = 1;
	}
	// 1이 터진것
	for (i = 1; i <= N; i++) {
		if (!alive[i] || K == 0) continue;
		con = 1;
		for (j = 0; j < graph[i].size(); j++) {
			if (!alive[graph[i][j]]) {
				con = 0;
				continue;
			}
		}
		if (con) {
			result.push_back(i);
			if (!fun_alive[i]) {
				fun_alive[i] = 1;
				K--;
			}
			for (j = 0; j < graph[i].size(); j++) {
				if (!fun_alive[graph[i][j]]) {
					fun_alive[graph[i][j]] = 1;
					K--;
				}
			}
		}
	}
	if (K) {
		cout << "-1" << "\n";
	} else {
		sort(result.begin(), result.end());
		cout << result.size() << "\n";
		for (i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}