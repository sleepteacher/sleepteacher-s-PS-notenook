#include <bits/stdc++.h>

using namespace std;

int arr[501], in[501], result[501];
vector<int> graph[501];
stack<int> S;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N;
	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> j;
		arr[i] = j;
		while (1) {
			cin >> j;
			if (j == -1) break;
			graph[j].push_back(i);
			in[i]++;
		}
	}
	for (i = 1; i <= N; i++) {
		if (!in[i]) {
			S.push(i);
			in[i]--;
		}
	}
	while (S.size()) {
		int vertex = S.top();
		S.pop();
		result[vertex] += arr[vertex];
		for (i = 0; i < graph[vertex].size(); i++) {
			in[graph[vertex][i]]--;
			result[graph[vertex][i]] = max(result[graph[vertex][i]], result[vertex]);
			if (!in[graph[vertex][i]]) {
				S.push(graph[vertex][i]);
				in[graph[vertex][i]]--;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}