#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
/*
0 to 1 S
1 to 0 E
*/

int UF[100001];
int UF_find(int a) {
	if (UF[a] == -1) {
		return a;
	}
	return UF[a] = UF_find(UF[a]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, TC, N, Q, X, cnt = 0, a, b;
	cin >> TC;
	while (++cnt <= TC) {
		cin >> N >> Q;
		cout << "Case #" << cnt << "\n";
		ull iter = 0;
		vector<pair<ull, ull>> arr;
		fill(UF, UF + 100001, -1);
		for (i = 1; i <= N; i++) {
			cin >> j;
			arr.push_back({j, i});
		}
		sort(arr.begin(), arr.end());
		for(i = 0; i < N; i++){
			iter = arr[i].first - iter;
			UF[]
		}
	}

	return 0;
}