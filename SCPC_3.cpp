#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(300001);
bool visited[300001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int TC, N, M, i, j, k, l, a, b, node, iter, search_dot[2], vern[2], con;
	long long result;
	queue<int> Q;
	cin >> TC;
	for (iter = 1; iter <= TC; iter++) {
		search_dot[0] = search_dot[1] = con = 0;
		vern[0] = vern[1] = 1;
		result = 0;
		graph = vector<vector<int>>(300001);
		fill(visited, visited + 300001, 0);
		cin >> N;
		for (i = 0; i <= N; i++) {
			cin >> a >> b;

			graph[a].push_back(b);
			graph[b].push_back(a);
			if (graph[a].size() == 3) {
				search_dot[0] = a;
			}
			if (graph[b].size() == 3) {
				search_dot[0] = b;
			}
		}
		for (i = 0; i < 3; i++) {
			if (graph[graph[search_dot[0]][i]].size() == 3) {
				search_dot[1] = graph[search_dot[0]][i];
			}
		}
		visited[search_dot[0]] = visited[search_dot[1]] = 1;
		for (i = 0; i < 3; i++) {
			if (graph[search_dot[0]][i] != search_dot[1]) {
				Q.push(graph[search_dot[0]][i]);
				while (Q.size()) {
					node = Q.front();
					Q.pop();
					visited[node] = 1;
					if (!visited[graph[node][0]]) {
						vern[con]++;
						Q.push(graph[node][0]);
					}
					if (!visited[graph[node][1]]) {
						vern[con]++;
						Q.push(graph[node][1]);
					}
				}
				vern[con]++;
				result += (long long)((long long)(vern[con]) * (long long)max(vern[con] - 1, 1)) / 2;
				con++;
			}
		}
		cout << "Case #" << iter << "\n";
		cout << result << "\n";
	}

	return 0;
}