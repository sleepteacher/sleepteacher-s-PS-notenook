#include <bits/stdc++.h>

using namespace std;

int val[51];

bool cmp(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, M, max_val = 0, min_val = 99, last, iter, min_size = 0, con = 0;
	string output[51], cache[2];
	cin >> N;
	/*
	답
	1. 제일 싼거 전부
	2.
	*/
	fill(val, val + 51, -1);
	for (i = 0; i < N; i++) {
		cin >> j;
		val[j] = i;
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		for (j = 0; j <= M - i; j++) {
			if (val[j] == -1) continue;
			cache[0] = output[i] + to_string(val[j]);
			cache[1] = output[i + j];
			sort(cache, cache + 2, cmp);
			if (cache[1] == "0") continue;
			output[i + j] = cache[1];
			cache[0].resize(0), cache[1].resize(0);
		}
		output[i] = "";
	}
	sort(output, output + 51, cmp);
	if (output[50] == "") output[50] = "0";
	cout << output[50] << "\n";
	return 0;
}