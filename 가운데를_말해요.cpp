#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N;
	vector<int> arr;
	priority_queue<int, vector<int>, less<int>> pq_max;
	priority_queue<int, vector<int>, greater<int>> pq_min;
	cin >> N;
	/*
	짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
	*/
	for (i = 1; i <= N; i++) {
		cin >> j;
		pq_max.push(j);
		if (i == 1) {
			cout << pq_max.top() << "\n";
			continue;
		} else if (i == 2) {
			pq_min.push(pq_max.top());
			pq_max.pop();
		}
		if (pq_max.top() > pq_min.top()) {
			int a = pq_max.top(), b = pq_min.top();
			pq_max.pop(), pq_min.pop();
			pq_min.push(a), pq_max.push(b);
		}
		while (pq_min.size() + i % 2 < pq_max.size()) {
			int a = pq_max.top();
			pq_max.pop();
			pq_min.push(a);
		}

		cout << pq_max.top() << "\n";
	}

	return 0;
}