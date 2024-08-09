#include <bits/stdc++.h>
using namespace std;

int ishave[100001], UF[100001], UF_val[100001];
int UF_find(int a) {
	if (UF[a] < 0) {
		return a;
	}
	return UF[a] = UF_find(a);
}

priority_queue<tuple<int, int, int>> pq;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, K, M, a, b, c, cnt = 0;
	long long diff;
	cin >> N >> K >> M;
	for (i = 0; i < N; i++) {
		cin >> ishave[i + 1];
	}
	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;
		pq.push({c, a, b});
	}
	for (i = 0; i < M; i++) {
		tie(a, b, c) = pq.top();
		pq.pop();
		if ()
	}

	return 0;
}
