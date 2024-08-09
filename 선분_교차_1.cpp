#include <bits/stdc++.h>

using namespace std;

long long CCW(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
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
long long isintersect(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d) {
	long long ab = CCW(a, b, c) * CCW(a, b, d);
	long long cd = CCW(c, d, a) * CCW(c, d, b);
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
	long long i, j, k, l;
	pair<long long, long long> loca[4];
	for (i = 0; i < 4; i++) cin >> loca[i].first >> loca[i].second;
	cout << isintersect(loca[0], loca[1], loca[2], loca[3]) << "\n";
	if (isintersect(loca[0], loca[1], loca[2], loca[3]) == 1) {
	}

	return 0;
}