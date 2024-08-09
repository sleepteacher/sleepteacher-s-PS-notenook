#include <bits/stdc++.h>

using namespace std;

int UF[1001], UF_val[1001];
int UF_get(int a) {
	if (UF[a] == a) {
		return a;
	}
	return UF[a] = UF_get(UF[a]);
}
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq_fine;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, less<tuple<int, int, int>>> pq_bad;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, a, b, c, result_fine = 0, result_bad = 0;
	cin >> N >> M;

	for (i = 0; i < M + 1; i++) {
		cin >> a >> b >> c;
		pq_fine.push({abs(c - 1), a, b});
		pq_bad.push({abs(c - 1), a, b});
	}
	for (i = 0; i <= N; i++) {
		UF[i] = i;
		UF_val[i] = 0;
	}
	while (pq_fine.size()) {
		a = get<0>(pq_fine.top()), b = get<1>(pq_fine.top()), c = get<2>(pq_fine.top());
		pq_fine.pop();
		if (UF_get(b) != UF_get(c)) {
			UF_val[UF_get(b)] += UF_val[UF_get(c)] + a;
			UF[UF_get(c)] = UF[UF_get(b)];
			result_fine = max(UF_val[UF_get(b)], result_fine);
		}
	}
	for (i = 0; i <= N; i++) {
		UF[i] = i;
		UF_val[i] = 0;
	}
	while (pq_bad.size()) {
		a = get<0>(pq_bad.top()), b = get<1>(pq_bad.top()), c = get<2>(pq_bad.top());
		pq_bad.pop();
		if (UF_get(b) != UF_get(c)) {
			UF_val[UF_get(b)] += UF_val[UF_get(c)] + a;
			UF[UF_get(c)] = UF[UF_get(b)];
			result_bad = max(UF_val[UF_get(b)], result_bad);
		}
	}
	cout << (result_bad * result_bad) - (result_fine * result_fine) << "\n";

	return 0;
}