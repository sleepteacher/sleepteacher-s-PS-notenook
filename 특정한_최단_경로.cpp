#include <bits/stdc++.h>

#define INF 999999999
using namespace std;

vector<pair<int, int>> graph[801];

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
int result[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
// first = vertex, second weight

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, j, k, l, V, E, a, b, c, cnt = 0, op1 = 0, op2 = 0;
	vector<int> start(4, 0);
	cin >> V >> E;
	start[0] = 1;
	for (i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	cin >> start[1] >> start[2];
	start[3] = V;
	for (int iter = 0; iter < 3; iter++) {
		fill(result, result + 801, INF);
		pq.push({start[cnt], 0});
		cnt++;
		while (!pq.empty()) {
			int ver = pq.top().first, weight = pq.top().second;
			// cout << ver << " " << weight << "\n";
			pq.pop();
			if (weight < result[ver]) {
				result[ver] = weight;
				for (i = 0; i < graph[ver].size(); i++) {
					int next = graph[ver][i].first, W = graph[ver][i].second;
					if (weight + W < result[next]) {
						pq.push({next, weight + W});
					}
				}
			}
		}
		// cout << "!";
		if (result[start[cnt]] == INF) {
			op1 = -1;
			break;
		} else {
			op1 += result[start[cnt]];
		}
	}
	i = start[1];
	start[1] = start[2];
	start[2] = i;
	cnt = 0;
	for (int iter = 0; iter < 3; iter++) {
		fill(result, result + 801, INF);
		pq.push({start[cnt], 0});
		cnt++;
		while (!pq.empty()) {
			int ver = pq.top().first, weight = pq.top().second;
			// cout << ver << " " << weight << "\n";
			pq.pop();
			if (weight < result[ver]) {
				result[ver] = weight;
				for (i = 0; i < graph[ver].size(); i++) {
					int next = graph[ver][i].first, W = graph[ver][i].second;
					if (weight + W < result[next]) {
						pq.push({next, weight + W});
					}
				}
			}
		}
		// cout << "!";
		if (result[start[cnt]] == INF) {
			op2 = -1;
			break;
		} else {
			op2 += result[start[cnt]];
		}
	}
	if (op1 == op2 && op1 == -1) {
		cout << -1;
	} else {
		if (op1 == -1) {
			cout << op2;
		} else if (op2 == -1) {
			cout << op1;
		} else {
			cout << min(op1, op2);
		}
	}

	return 0;
}
