#include <bits/stdc++.h>

using namespace std;

#define pll pair<long long, long long>

int CCW(pll a, pll b, pll c) {
	// x1(y2-y3)-x2(y1-y3)+x3(y1-y2)
	long long x1, x2, x3, y1, y2, y3;
	tie(x1, y1) = a, tie(x2, y2) = b, tie(x3, y3) = c;
	if (x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2) < 0)
		return -1;
	else if (x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2) == 0)
		return 0;
	else
		return 1;
}
int isintersect(pll a, pll b, pll c, pll d) {
	int ab = CCW(a, b, c) * CCW(a, b, d);
	int cd = CCW(c, d, a) * CCW(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int i, j, k, l, N, a, b, c, d, e, iter;
	long long result = 0, val;
	vector<tuple<long long, pll, pll>> loca;
	tuple<long long, pll, pll> input;
	pll p1, p2, p3, p4;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a >> b >> c >> d >> e;
		input = {e, {a, b}, {c, d}};
		loca.push_back(input);
	}
	sort(loca.begin(), loca.end(), greater<>());
	for (i = 0; i < N; i++) {
		iter = 1;
		tie(val, p1, p2) = loca[N - i - 1];
		for (j = 0; j < N - 1 - i; j++) {
			p3 = get<1>(loca[j]);
			p4 = get<2>(loca[j]);
			iter += isintersect(p1, p2, p3, p4);
		}
		result += (long long)iter * val;
	}
	cout << result;

	return 0;
}