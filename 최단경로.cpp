#include <bits/stdc++.h>

#define INF 99999999
using namespace std;

vector<pair<int, int>> graph[20001];

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

bool visited[20001];
int result[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
// first = vertex, second weight

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, j, k, l, V, E, start, a, b, c;
	cin >> V >> E >> start;
	fill(result, result + 20001, INF);
	for (i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		// graph[b].push_back({a, c});
	}
	pq.push({start, 0});
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
	for (i = 1; i <= V; i++) {
		if (result[i] != INF) {
			cout << result[i] << "\n";
		} else {
			cout << "INF" << "\n";
		}
	}

	return 0;
}
