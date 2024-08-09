#include <bits/stdc++.h>

using namespace std;

int UF[100000];

struct cmp {
	bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
		return (get<0>(a) < get<0>(b));
	}
};

int UF_find(int a) {
	if (UF[a] < 0) {
		return a;
	}
	return UF[a] = UF_find(UF[a]);
}

vector<pair<int, int>> arr1, arr2, arr3;
vector<tuple<int, int, int>> A;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, a, b, c, vertex, cnt = 0;
	long long result = 0;
	fill(UF, UF + 100000, -1);
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b >> c;
		arr1.push_back({a, i});
		arr2.push_back({b, i});
		arr3.push_back({c, i});
	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	sort(arr3.begin(), arr3.end());
	for (i = 1; i < N; i++) {
		int fx = i - 1;
		A.push_back({abs(arr1[fx].first - arr1[i].first), arr1[fx].second, arr1[i].second});
		A.push_back({abs(arr2[fx].first - arr2[i].first), arr2[fx].second, arr2[i].second});
		A.push_back({abs(arr3[fx].first - arr3[i].first), arr3[fx].second, arr3[i].second});
	}
	sort(A.begin(), A.end());
	for (i = 0; i < A.size(); i++) {
		tie(a, b, c) = A[i];
		if (UF_find(b) != UF_find(c)) {
			UF[UF_find(b)] = UF_find(c);
			cnt++;
			result += (long long)a;
		}
		if (cnt == N - 1) break;
	}

	cout << result << "\n";
	return 0;
}