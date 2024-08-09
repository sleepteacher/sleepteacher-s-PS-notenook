#include <bits/stdc++.h>

using namespace std;

int UF[200001], UF_CNT[200001];

int UF_find(int a) {
	if (UF[a] == -1) return a;
	return UF[a] = UF_find(UF[a]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int TC, N, i, j, k, l;

	cin >> TC;
	while (TC--) {
		cin >> N;
		int node_iter = 1;
		map<string, int> node;
		string a, b;
		fill(UF, UF + 200001, -1);
		fill(UF_CNT, UF_CNT + 200001, 1);
		for (i = 0; i < N; i++) {
			cin >> a >> b;
			if (node.find(a) == node.end())
				node[a] = node_iter++;
			if (node.find(b) == node.end())
				node[b] = node_iter++;
			if (UF_find(node[a]) != UF_find(node[b])) {
				UF_CNT[UF_find(node[a])] += UF_CNT[UF_find(node[b])];
				// UF_CNT[UF_find(node[b])] = 0;
				UF[UF_find(node[b])] = UF_find(node[a]);
			}
			cout << UF_CNT[UF_find(node[a])] << "\n";
		}
	}

	return 0;
}