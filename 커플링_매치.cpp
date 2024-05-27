#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, result = 0;
	map<string, vector<string>> P;
	vector<string> arr[10000];
	string a, b;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		if (b[0] != '-') {
			P[b].push_back(a);
		}
	}
	for (auto p = P.begin(); p != P.end(); p++) {
		if ((*p).second.size() == 2) {
		}
	}
	for (auto p = P.begin(); p != P.end(); p++) {
		if ((*p).second.size() == 2) {
			arr[result] = {(*p).second[0], (*p).second[1]};
			result++;
		}
	}
	cout << result << "\n";
	for (i = 0; i < result; i++) {
		cout << arr[i][0] << " "
			 << arr[i][1] << "\n ";
	}

	return 0;
}