#include <bits/stdc++.h>

using namespace std;

vector<string> recur(vector<string> R, int N, int iter) {
	if (iter == N) return R;
	int i, j, k, l, L = R[R.size() - 1].size(), S = R.size();
	vector<string> tmp;
	for (i = 0; i < S; i++) {
		tmp.push_back("");
		for (j = 0; j < S; j++) {
			tmp[i] += " ";
		}
		tmp[i] += R[i];
		for (j = 0; j < S; j++) {
			tmp[i] += " ";
		}
	}
	for (i = 0; i < S; i++) {
		tmp.push_back("");
		tmp[S + i] += R[i];
		tmp[S + i] += " ";
		tmp[S + i] += R[i];
	}
	return recur(tmp, N, iter * 2);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, iter;
	long long it = 0;
	vector<string> result, start = {"  *  ", " * * ", "*****"};
	cin >> N;
	N /= 3;
	result = recur(start, N, 1);
	for (i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}