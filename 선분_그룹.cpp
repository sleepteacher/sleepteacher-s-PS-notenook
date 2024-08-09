#include <bits/stdc++.h>

using namespace std;

int UF[3000], result[3000];
pair<int, int> loca[3000][2];
int UF_find(int a) {
	if (UF[a] == -1) {
		return a;
	}
	return UF[a] = UF_find(UF[a]);
}

int CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	// x1(y2-y3)-x2(y1-y3)+x3(y1-y2)
	int x1, x2, x3, y1, y2, y3;
	tie(x1, y1) = a, tie(x2, y2) = b, tie(x3, y3) = c;
	if (x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2) < 0)
		return -1;
	else if (x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2) == 0)
		return 0;
	else
		return 1;
}
int intersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
	int ab = CCW(a, b, c) * CCW(a, b, d);
	int cd = CCW(c, d, a) * CCW(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return (c <= b && a <= d);
	}
	return (ab <= 0 && cd <= 0);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, op1 = 0, op2 = 0;

	cin >> N;
	fill(UF, UF + 3000, -1);
	fill(result, result + 3000, 0);
	for (i = 0; i < N; i++)
		for (j = 0; j < 2; j++) cin >> loca[i][j].first >> loca[i][j].second;

	for (i = 0; i < N - 1; i++) {
		for (j = i + 1; j < N; j++) {
			if (UF_find(i) != UF_find(j) && intersect(loca[i][0], loca[i][1], loca[j][0], loca[j][1])) {
				UF[UF_find(j)] = UF_find(i);
			}
		}
	}
	for (i = 0; i < N; i++) {
		result[UF_find(i)]++;
		if (result[UF_find(i)] == 1) op2++;
		op1 = max(result[UF_find(i)], op1);
	}
	cout << op2 << "\n";
	cout << op1;

	return 0;
}