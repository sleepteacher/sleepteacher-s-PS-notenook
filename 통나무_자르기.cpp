#include <bits/stdc++.h>

using namespace std;

struct compare {
	bool operator()(const pair<int, int> &a, pair<int, int> &b) {
		return (a.second - a.first <= b.second - b.first);
	}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, L, C, K;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	set<int> a;
	cin >> L >> K >> C;
	for (i = 0; i < L; i++) {
		cin >> j;
		a.insert(j);
	}
	for (i = 0; i < a.; i++) {
		cin >> j;
		a.insert(j);
	}
	/*
	1. a가 C보다 작거나 같을 때 -> 깡 출력

	*/

	return 0;
}