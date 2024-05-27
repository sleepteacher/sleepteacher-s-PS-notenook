#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> info[100001];
pair<int, pair<int, int>> dp[100001][17];
queue<int> Q;
int depth[100001];
bool visited[100001];

int main() {
	int N, M, a, b, c, i, j, k, l;
	cin >> N;
	// tree 제작
	cin >> a >> b >> c;
	Q.push(a);
	visited[a] = 1;
	dp[a][0].first = 0;
	// min, max
	info[a].push_back({b, c});
	info[b].push_back({a, c});
	for (i = 0; i < N - 2; i++) {
		cin >> a >> b >> c;
		info[a].push_back({b, c});
		info[b].push_back({a, c});
	}
	// depth 연산 및 dp table
	while (!Q.empty()) {
		int root = Q.front();
		Q.pop();
		for (i = 0; i < info[root].size(); i++) {
			if (!visited[info[root][i].first]) {
				int now = info[root][i].first;
				visited[now]++;
				Q.push(now);
				depth[now] = depth[root] + 1;
				dp[now][0].first = root;
				dp[now][0].second = {info[root][i].second, info[root][i].second};
				for (j = 1; j < 16; j++) {
					int pre = dp[now][j - 1].first;
					if (dp[now][pre].first == 0) {
						dp[now][j].first = dp[now][pre].first;
						dp[now][j].second = {min(info[root][i].second, dp[root][0].second.first), min(info[root][i].second, dp[root][0].second.second)};
					}
				}
				// dp
			}
		}
	}
	/*
	풀이 목적 자기 자신과 부모 노드 사이의 최대-최소를 구한 뒤 최소 공통 조상 구하고
	*/
	cin >> M;
	for (i = 0; i < M; i++) {
	}

	return 0;
}