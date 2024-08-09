#include <bits/stdc++.h>

using namespace std;

long double CCW(pair<long double, long double> a, pair<long double, long double> b, pair<long double, long double> c) {
	// x1(y2-y3)-x2(y1-y3)+x3(y1-y2)
	long double x1, x2, x3, y1, y2, y3;
	tie(x1, y1) = a, tie(x2, y2) = b, tie(x3, y3) = c;
	if (x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2) < 0)
		return -1;
	else if (x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2) == 0)
		return 0;
	else
		return 1;
}
long double intersect(pair<long double, long double> a, pair<long double, long double> b, pair<long double, long double> c, pair<long double, long double> d) {
	long double ab = CCW(a, b, c) * CCW(a, b, d);
	long double cd = CCW(c, d, a) * CCW(c, d, b);
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
	int i, j, k, l;
	pair<long double, long double> loca[4], P;
	for (i = 0; i < 4; i++) cin >> loca[i].first >> loca[i].second;

	if (intersect(loca[0], loca[1], loca[2], loca[3])) {
		long double x1, x2, x3, x4, y1, y2, y3, y4;
		cout << 1 << "\n";
		if (loca[1] < loca[0]) swap(loca[0], loca[1]);
		if (loca[3] < loca[2]) swap(loca[2], loca[3]);
		tie(x1, y1) = loca[0];
		tie(x2, y2) = loca[1];
		tie(x3, y3) = loca[2];
		tie(x4, y4) = loca[3];
		long double bm = ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
		if (bm != 0) {
			long double result_x = (long double)((x1 * y2 - y1 * x2) * (x3 - x4) - (x3 * y4 - y3 * x4) * (x1 - x2)) / bm;
			long double result_y = (long double)((x1 * y2 - y1 * x2) * (y3 - y4) - (x3 * y4 - y3 * x4) * (y1 - y2)) / bm;
			printf("%0.16Lf %0.16Lf", result_x, result_y);

		} else {
			if (loca[1] < loca[0]) swap(loca[0], loca[1]);
			if (loca[3] < loca[2]) swap(loca[2], loca[3]);
			tie(x1, y1) = loca[0];
			tie(x2, y2) = loca[1];
			tie(x3, y3) = loca[2];
			tie(x4, y4) = loca[3];
			if ((loca[0] == loca[3] && loca[1] != loca[2])) cout << x1 << " " << y1;
			if ((loca[0] != loca[3] && loca[1] == loca[2])) cout << x3 << " " << y3;
		}
	} else {
		cout << 0 << "\n";
	}
	return 0;
}